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
    char filename[] = "test_8.csv";
    std::ofstream fout;
    fout.open(filename, std::ios::trunc);
    fout.close();

    //ヘッダー指定
    fout.open(filename, std::ios_base::app);
    fout << "N"
         << ","
         << "M"
         << ","
         << "time[ms]"
         << "\n";
    fout.close();

    for (int N = 1e1; N < 1e3; N++)
    {
        for (int M = 1e1; M < N; M++)
        {
            std::vector<std::vector<int>> c(N + 1, std::vector<int>(N + 1));
            std::vector<int> dp(N);
            std::vector<int> dp_tmp(N);
            int tmp;
            double Ans;

            for (int i = 0; i < N + 1; ++i)
            {
                for (int j = 0; j < N + 1; ++j)
                {
                    c[i][j] = rand() % 10 + 1;
                }
            }

            clock_t start = clock();

            //1分割
            for (int i = 0; i < N; i++)
            {
                dp[i] = c[0][i];
                dp_tmp[i] = c[0][i];
            }
            //0は使わない
            dp[0] = -INF;
            dp_tmp[0] = -INF;

            //2分割 - M-1分割
            for (int m = 2; m <= M; m++)
            {
                //m-1分割から
                for (int i = m; i < N; i++)
                {
                    dp[i] = -INF;

                    for (int j = m - 1; j < i; j++)
                    {
                        chmax(dp[i], dp_tmp[j] + c[j][i]);
                    }
                }

                //更新
                for (int i = 0; i < N; i++)
                {
                    dp_tmp[i] = dp[i];
                }
            }

            //M分割
            tmp = -INF;
            for (int j = M - 1; j < N; j++)
            {
                chmax(tmp, dp[j] + c[j][N]);
            }
            Ans = (double)tmp / (double)M;

            clock_t end = clock();

            std::cout << Ans << std::endl;
            const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
            std::cout << time << std::endl;

            fout.open(filename, std::ios_base::app);
            fout << N << "," << M << "," << std::fixed << std::setprecision(5) << time << "\n";
            fout.close();
        }
    }

    return 0;
}