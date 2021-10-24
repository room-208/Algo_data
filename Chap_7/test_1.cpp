#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>

const int INF = 1 << 30;

int main()
{
    //ファイル削除
    char filename[] = "test_1.csv";
    std::ofstream fout;
    fout.open(filename, std::ios::trunc);
    fout.close();

    //ヘッダー指定
    fout.open(filename, std::ios_base::app);
    fout << "N"
         << ","
         << "time[ms]"
         << "\n";
    fout.close();

    for (int N = 1e1; N < 1e4; N++)
    {
        std::vector<int> a(N), b(N);
        int counter;
        int pointer;
        int key;
        int tmp;

        for (int i = 0; i < N; i++)
        {
            a[i] = rand() % 10 + 1;
            b[i] = rand() % 10 + 1;
            //std::cout << a[i] << "\t" << b[i] << "\n";
        }
        //std::cout << "\n";

        clock_t start = clock();

        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        a.push_back(INF);
        b.push_back(INF);

        /*
        for (int i = 0; i <= N; i++)
        {
            std::cout << a[i] << "\t" << b[i] << "\n";
        }
        */

        counter = 0;
        pointer = 0;
        for (int i = 0; i < N; i++)
        {
            key = a[i];
            for (int j = pointer; j < N; j++)
            {
                if (b[j] > key)
                {
                    counter++;
                    pointer = j + 1;
                    break;
                }
            }
        }

        clock_t end = clock();

        std::cout << counter << std::endl;
        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}