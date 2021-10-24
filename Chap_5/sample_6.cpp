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

//参照渡しじゃないと滅茶遅い
long long rec(int i, std::vector<long long> &h, std::vector<long long> &dp)
{

    if (dp[i] < INF)
    {
        return dp[i];
    }
    if (i == 0)
    {
        return dp[i];
    }

    long long res = INF;

    chmin(res, rec(i - 1, h, dp) + abs(h[i] - h[i - 1]));

    if (i > 1)
    {
        chmin(res, rec(i - 2, h, dp) + abs(h[i] - h[i - 2]));
    }

    dp[i] = res;

    return res;
}

int main()
{
    //ファイル削除
    char filename[] = "data_6.csv";
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
        dp[0] = 0;

        for (int i = 0; i < N; i++)
        {
            h[i] = rand() % 10 + 1;
        }

        clock_t start = clock();

        std::cout << rec(N - 1, h, dp) << std::endl;

        clock_t end = clock();

        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}