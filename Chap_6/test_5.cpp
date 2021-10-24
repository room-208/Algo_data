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
    char filename[] = "test_5.csv";
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

    for (int N = 1e1; N < 1e4 + 1; N++)
    {
        std::vector<int> a(N), b(N);
        int K = rand() % (N * N) + 1;
        int C;
        int right, mid, left;
        int key;
        int tmp;
        int count;

        for (int i = 0; i < N; i++)
        {
            a[i] = rand() % (5 * N) + 1;
            b[i] = rand() % (5 * N) + 1;
        }

        clock_t start = clock();

        //ソートO(NlogN)
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        a.push_back(INF);
        b.push_back(INF);

        C = a[N - 1] * b[N - 1];
        /*
        for (int i = 0; i <= N; i++)
        {
            std::cout << a[i] << "\t" << b[i] << std::endl;
        }
        std::cout << "\n";
        */

        std::cout << K << "\t" << C << "\n";

        right = C;
        left = 0;
        while (right - left > 1)
        {

            mid = (int)floor(((double)right + (double)left) / 2.);

            //a_i*b_j>midのカウント
            count = 0;
            for (int i = 0; i < N; i++)
            {
                key = (int)floor((double)mid / (double)a[i]);
                //std::cout << a[i] << "\t" << mid << "\t" << key << "\n";
                auto iter = std::upper_bound(b.begin(), b.end(), key);

                tmp = b.end() - iter - 1;
                count += tmp;
            }

            if (N * N - count <= K - 1)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }

        clock_t end = clock();

        /*
        std::vector<int> d(N * N);

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int num = N * i + j;
                d[num] = a[i] * b[j];
            }
        }

        std::sort(d.begin(), d.end());

        std::cout << "\n";
        for (int i = 0; i < N * N; i++)
        {
            std::cout << d[i] << "\n";
        }
        std::cout << "\n";
        */

        //std::cout << right << "\t" << d[K - 1] << std::endl;

        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}