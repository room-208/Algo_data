#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>

const int INF = 1 << 30;

int main()
{
    //ファイル削除
    char filename[] = "test_4.csv";
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
        std::vector<int> a(N);
        int x_r, x_l;
        int M = rand() % N + 1;
        int x;
        int tmp;
        int count;
        int prev;

        for (int i = 0; i < N; i++)
        {
            a[i] = rand() % (2 * N) + 1;
        }

        //ソート
        std::sort(a.begin(), a.end());

        /*
        for (auto it = a.begin(); it != a.end(); it++)
        {
            std::cout << *it << std::endl;
        }
        std::cout << std::endl;
        */

        clock_t start = clock();

        x_r = a[N - 1];
        x_l = 0;
        while (x_r - x_l > 1)
        {
            x = (int)floor(((double)x_r + (double)x_l) / 2.);
            //std::cout << x << std::endl;

            count = 1;
            prev = 0;
            for (int i = 0; i < N; i++)
            {
                tmp = a[i] - a[prev];

                if (tmp >= x)
                {
                    count++;
                    prev = i;
                }
            }

            if (count >= M)
            {
                x_l = x;
            }
            else
            {
                x_r = x;
            }
        }

        std::cout << x_l << std::endl;

        clock_t end = clock();

        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}