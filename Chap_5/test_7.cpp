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

void Edit_dist(int N, int M, std::string &S, std::string &T, std::vector<std::vector<int>> &dp)
{
    int i, j;

    //空白文字計算
    for (i = 0; i <= N; i++)
    {
        dp[i][0] = i;
    }
    for (j = 0; j <= M; j++)
    {
        dp[0][j] = j;
    }

    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= M; j++)
        {
            if (S[i] == T[j])
            {
                chmin(dp[i][j], dp[i - 1][j - 1]);
            }

            chmin(dp[i][j], dp[i - 1][j] + 1);
            chmin(dp[i][j], dp[i][j - 1] + 1);
        }
    }
}

int main()
{
    //ファイル削除
    char filename[] = "test_7.csv";
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

    /*
    std::cout << len << "\n";
    for (int i = 0; i < len; i++)
    {
        std::cout << CHARS[i];
    }
    std::cout << "\n";
    */

    for (int N = 1e1; N < 5e2; N++)
    {
        for (int M = 1e1; M < 5e2; M++)
        {
            std::string S(N, 'a'), T(M, 'a');
            std::vector<std::vector<int>> dp(N + 1, std::vector<int>(M + 1, INF));
            int tmp;
            int max_len;

            /*
            for (int i = 0; i <= N; i++)
            {
                for (int j = 0; j <= M; j++)
                {
                    std::cout << dp[i][j] << "\t";
                }
                std::cout << "\n";
            }
            */


            /*
            N=14;
            M=16;
            S = "pirikapirirara";
            T = "poporinapeperuto";
            */

            for (int i = 0; i < N; i++)
            {
                tmp = rand() % len;
                S[i] = CHARS[tmp];
                //std::cout << S[i];
            }
            //std::cout << std::endl;
            for (int j = 0; j < M; j++)
            {
                tmp = rand() % len;
                T[j] = CHARS[tmp];
                //std::cout << T[j];
            }
            //std::cout << std::endl;

            clock_t start = clock();

            Edit_dist(N, M, S, T, dp);

            clock_t end = clock();

            /*
            for (int i = 0; i <= N; i++)
            {
                for (int j = 0; j <= M; j++)
                {
                    std::cout << dp[i][j] << "\t";
                }
                std::cout << "\n";
            }
            */

            max_len = ((N + M) - dp[N][M]) / 2;
            std::cout << max_len << std::endl;

            const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
            std::cout << time << std::endl;

            fout.open(filename, std::ios_base::app);
            fout << N << "," << M << "," << std::fixed << std::setprecision(5) << time << "\n";
            fout.close();
        }
    }

    return 0;
}