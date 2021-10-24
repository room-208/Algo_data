#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>

const long long INF = 1LL << 60;

template <class T>
void chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
    }
}

int main()
{
    //ファイル削除
    char filename[] = "data_4.csv";
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
        std::vector<long long> h(N);
        std::vector<long long> dp(N, INF);
        long long tmp;
        dp[0] = 0;

        for (int i = 0; i < N; i++)
        {
            h[i] = rand() % 10 + 1;
        }

        clock_t start = clock();

        for (int i = 0; i < N - 1; i++)
        {
            if (i < N - 2)
            {
                tmp = dp[i] + llabs(h[i + 1] - h[i]);
                chmin(dp[i + 1], tmp);

                tmp = dp[i] + llabs(h[i + 2] - h[i]);
                chmin(dp[i + 2], tmp);
            }
            if (i + 1 == N - 1)
            {
                tmp = dp[i] + llabs(h[i + 1] - h[i]);
                chmin(dp[i + 1], tmp);
            }
        }

        std::cout << dp[N - 1] << std::endl;

        clock_t end = clock();

        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}