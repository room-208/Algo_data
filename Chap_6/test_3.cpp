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
    char filename[] = "test_3.csv";
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
        std::vector<int> A(N * N);
        int M = rand() % (5 * N) + 1;
        int num;
        int tmp;
        int max_value;
        int key;

        srand(1);
        for (int i = 0; i < N; i++)
        {
            a[i] = rand() % (6 * N) + 1;
        }

        clock_t start = clock();

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                num = N * i + j;
                A[num] = -(a[i] + a[j]);
                //std::cout << A[num] << "\n";
            }
        }
        //std::cout << "\n";

        std::sort(A.begin(), A.end());

        max_value = -INF;
        for (int i = 0; i < N * N - 1; i++)
        {
            //std::cout << A[i] << "\n";

            key = -A[i] - M;

            if (key <= 0)
            {
                auto iter = std::lower_bound(A.begin(), A.end(), key);

                tmp = -*iter - A[i];
                if (tmp > max_value)
                {
                    max_value = tmp;
                }
            }
        }

        clock_t end = clock();

        std::cout << M << "\t" << max_value << std::endl;
        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}