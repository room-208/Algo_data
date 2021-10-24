#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>

const int INF = 1 << 30;
const char CHARS[] = "abcdefghijklmnopqrstuvwxyz";
const int len = sizeof(CHARS);

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
    char filename[] = "data_9.csv";
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
        std::vector<std::vector<int>> c(N + 1, std::vector<int>(N + 1));
        std::vector<int> dp(N + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < N + 1; ++i)
        {
            for (int j = 0; j < N + 1; ++j)
            {
                c[i][j] = rand() % 10 + 1;
            }
        }

        clock_t start = clock();

        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j < i; j++)
            {
                chmin(dp[i], dp[j] + c[i][j]);
            }
        }

        clock_t end = clock();

        //std::cout << dp[N] << std::endl;
        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        //std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}