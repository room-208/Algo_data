#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>

const long long INF = 1LL << 60;

template <class T>
void chmax(T &a, T b)
{
    if (b > a)
    {
        a = b;
    }
}

//参照渡しじゃないと滅茶遅い
void Cal_Knapsack(int N, int W, std::vector<long long> &value, std::vector<long long> &weight, std::vector<std::vector<long long>> &dp)
{
    int i, w;

    for (i = 0; i < N; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (w - weight[i] >= 0)
            {
                chmax(dp[i + 1][w], dp[i][w - weight[i]] + value[i]);
            }

            chmax(dp[i + 1][w], dp[i][w]);
        }
    }
}

int main()
{
    //ファイル削除
    char filename[] = "data_7.csv";
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
        int W = 1e2;
        std::vector<long long> value(N), weight(N);
        std::vector<std::vector<long long>> dp(N + 1, std::vector<long long>(W + 1, 0));

        for (int i = 0; i < N; i++)
        {
            value[i] = rand() % 10 + 1;
            weight[i] = rand() % 10 + 1;

            //std::cout << value[i] << "\t" << weight[i] << "\n";
        }

        /*
        for (int i = 0; i <= N; i++)
        {
            for (int w = 0; w < W; w++)
            {
                std::cout << dp[i][w] << "\t";
            }
            std::cout << "\n";
        }
        */

        clock_t start = clock();

        Cal_Knapsack(N, W, value, weight, dp);

        std::cout << dp[N][W] << std::endl;

        clock_t end = clock();

        /*
        for (int i = 0; i <= N; i++)
        {
            for (int w = 0; w <= W; w++)
            {
                std::cout << dp[i][w] << "\t";
            }
            std::cout << "\n";
        }
        */

        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}