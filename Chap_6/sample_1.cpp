#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>

int main()
{
    //ファイル削除
    char filename[] = "data_1.csv";
    std::ofstream fout;
    fout.open(filename, std::ios::trunc);
    fout.close();

    //ヘッダー指定
    fout.open(filename, std::ios_base::app);
    fout << "N"
         << ","
         << "count"
         << "\n";
    fout.close();

    for (int N = 1e1; N < 1e10; N++)
    {
        std::vector<long long> a(N);
        int tmp;
        int count;
        int key = 1;
        int left, right;

        a[0] = 1;
        for (int i = 1; i < N; i++)
        {
            a[i] = 1;
            a[i] = a[i - 1] + (rand() % 3 + 1);
        }
        /*
        for (int i = 0; i < N; i++)
        {
            std::cout << a[i] << std::endl;
        }
        */

        right = N - 1;
        left = 0;
        count = 0;

        clock_t start = clock();

        while (left < right)
        {
            count++;
            tmp = (int)floor(((double)left + (double)right) / 2.);

            if (key == a[tmp])
            {
                left = tmp;
                right = tmp;
            }
            else if (key < a[tmp])
            {
                right = tmp - 1;
            }
            else
            {
                left = tmp + 1;
            }
        }

        //std::cout << a[left] << std::endl;

        clock_t end = clock();

        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        //std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << count << "\n";
        fout.close();
    }

    return 0;
}