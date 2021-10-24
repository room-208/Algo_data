#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>

const int INF = 1 << 30;

template <class T>
void chmax(T &a, T b)
{
    if (b > a)
    {
        a = b;
    }
}

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
        std::vector<int> a(N), b(N), c(N);
        std::vector<std::vector<int>> dp(N + 1, std::vector<int>(3, -INF));
        int ans;

        for (int j = 0; j < 3; ++j)
        {
            dp[0][j] = 0;
        }

        for (int i = 0; i < N; ++i)
        {
            a[i] = rand() % 10 + 1;
            b[i] = rand() % 10 + 1;
            c[i] = rand() % 10 + 1;
        }

        clock_t start = clock();

        for (int i = 0; i < N; i++)
        {
            chmax(dp[i + 1][1], dp[i][0] + b[i]);
            chmax(dp[i + 1][2], dp[i][0] + c[i]);
            chmax(dp[i + 1][2], dp[i][1] + c[i]);
            chmax(dp[i + 1][0], dp[i][1] + a[i]);
            chmax(dp[i + 1][0], dp[i][2] + a[i]);
            chmax(dp[i + 1][1], dp[i][2] + b[i]);
        }

        clock_t end = clock();

        ans = -INF;
        for (int j = 0; j < 3; ++j)
        {
            chmax(ans, dp[N][j]);
        }

        std::cout << ans << std::endl;
        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}