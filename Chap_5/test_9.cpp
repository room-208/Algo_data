#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>

//累積和による計算

const int INF = 1 << 30;

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
    char filename[] = "test_9.csv";
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

    for (int N = 1e1; N < 5e2; N++)
    {
        srand(1);
        std::vector<int> a(N);
        //dp[i][j]=[i,j)
        std::vector<std::vector<int>> dp(N + 1, std::vector<int>(N + 1, INF));
        //s[i]=[0,i)
        std::vector<int> s(N + 1);
        int w;

        for (int i = 0; i < N; ++i)
        {
            a[i] = rand() % 10 + 1;
            //std::cout << a[i] << std::endl;
        }
        //std::cout << std::endl;

        s[0] = 0;
        for (int i = 0; i <= N - 1; i++)
        {
            s[i + 1] = s[i] + a[i];
        }
        /*
        for (int i = 0; i <= N; i++)
        {
            std::cout << s[i] << std::endl;
        }
        std::cout << std::endl;
        */

        clock_t start = clock();

        //初期化(合成していなければ費用は0)
        w = 1;
        for (int i = 0; i <= N - w; ++i)
        {
            dp[i][i + w] = 0;
        }

        //w>=2
        for (w = 2; w <= N; w++)
        {
            for (int i = 0; i <= N - w; ++i)
            {
                for (int j = i + 1; j <= i + w - 1; ++j)
                {
                    chmin(dp[i][i + w], dp[i][j] + dp[j][i + w] + s[i + w] - s[i]);
                }
            }
        }

        clock_t end = clock();

        /*
        for (int i = 0; i <= N; ++i)
        {
            for (int j = 0; j <= N; ++j)
            {
                std::cout << dp[i][j] << "\t";
            }
            std::cout << "\n";
        }
        */

        std::cout << dp[0][N] << std::endl;
        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}