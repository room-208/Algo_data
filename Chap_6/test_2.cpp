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
    char filename[] = "test_2.csv";
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
        std::vector<int> a(N), b(N), c(N);
        std::vector<int> b_c_count(N), b_c_sum(N + 1);
        int key;
        int count;
        int order;

        srand(1);
        for (int i = 0; i < N; i++)
        {
            a[i] = rand() % N + 1;
            b[i] = rand() % N + 1;
            c[i] = rand() % N + 1;

            //std::cout << a[i] << "\t" << b[i] << "\t" << c[i] << std::endl;
        }

        clock_t start = clock();

        //ソートO(NlogN)
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        std::sort(c.begin(), c.end());

        //INFを末尾に追加
        a.push_back(INF);
        b.push_back(INF);
        c.push_back(INF);

        /*
        for (int i = 0; i < N + 1; i++)
        {
            std::cout << a[i] << "\t" << b[i] << "\t" << c[i] << std::endl;
        }
        */

        //b_c_count計算O(N)
        for (int i = 0; i < N; i++)
        {
            //O(logN)
            key = b[i];
            auto iter_c = std::upper_bound(c.begin(), c.end(), key);

            if (*iter_c == INF)
            {
                b_c_count[i] = 0;
            }
            else
            {
                b_c_count[i] = c.end() - iter_c - 1;
            }
        }

        /*
        for (int i = 0; i < N; i++)
        {
            std::cout << b_c_count[i] << std::endl;
        }
        std::cout << std::endl;
        */

        //b_c_sum計算O(N)
        b_c_sum[0] = 0;
        for (int i = 1; i <= N; i++)
        {
            b_c_sum[i] = b_c_sum[i - 1] + b_c_count[i - 1];
        }

        /*
        for (int i = 0; i <= N; i++)
        {
            std::cout << b_c_sum[i] << std::endl;
        }
        std::cout << std::endl;
        */

        //count計算O(N)
        count = 0;
        for (int i = 0; i < N; i++)
        {
            //O(logN)
            key = a[i];
            auto iter_b = std::upper_bound(b.begin(), b.end(), key);

            if (*iter_b != INF)
            {
                order = iter_b - b.begin();
                //std::cout << a[i] << "\t" << *iter_b << "\t" << order << std::endl;

                count += (b_c_sum[N] - b_c_sum[order]);
            }
        }

        clock_t end = clock();

        std::cout << count << std::endl;
        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}