#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>
#include <bitset>

const int INF = 1 << 30;

template <class T>
void chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
    }
}

/*
//誤解答
int main()
{
    //ファイル削除
    char filename[] = "test_6.csv";
    std::ofstream fout;
    fout.open(filename, std::ios::trunc);
    fout.close();

    //ヘッダー指定
    fout.open(filename, std::ios_base::app);
    fout << "N"
         << ","
         << "W"
         << ","
         << "time[ms]"
         << "\n";
    fout.close();

    for (int N = 1e1; N < 5e2; N++)
    {
        for (int W = 1e1; W < 5e2; W++)
        {
            std::vector<int> a(N), m(N);
            std::vector<int> bit(N, 0);
            int bit_list = (1 << 0);
            int bit_list_tmp = bit_list;
            int tmp;

            std::cout << std::endl;
            std::cout << std::bitset<20>(bit_list) << std::endl;
            std::cout << std::bitset<20>(bit_list_tmp) << std::endl;
            std::cout << std::endl;

            //値代入
            //std::cout << std::endl;
            for (int i = 0; i < N; i++)
            {
                a[i] = rand() % 10 + 1;
                m[i] = rand() % 10 + 1;
                //std::cout << a[i] << "\t" << m[i] << std::endl;
            }
            //std::cout << std::endl;

            clock_t start = clock();

            //bit作成

            //std::cout << std::endl;
            for (int i = 0; i < N; i++)
            {
                tmp = (int)floor((double)W / (double)a[i]);
                chmin(tmp, m[i]);

                //a[i]間隔のbit
                for (int j = 0; j < tmp; j++)
                {
                    bit[i] = (bit[i] << a[i]);
                    bit[i] = bit[i] + (1 << a[i]);
                }
                bit[i] = bit[i] + (1 << 0);

                //std::cout << tmp << "\t" << std::bitset<30>(bit[i]) << std::endl;
            }
            //std::cout << std::endl;

            //std::cout << std::endl;
            for (int i = 0; i < N; i++)
            {
                //桁調べ
                for (int w = 0; w <= W - 1; w++)
                {
                    if (bit_list_tmp & (1 << w))
                    {
                        tmp = (bit[i] << w);

                        bit_list = bit_list | tmp;
                    }
                }

                //更新
                bit_list_tmp = bit_list;
            }
            //std::cout << std::endl;

            clock_t end = clock();

            //W桁目のbitが立っているかどうか
            if (bit_list & (1 << W))
            {
                std::cout << "true" << std::endl;
            }
            else
            {
                std::cout << "false" << std::endl;
            }

            const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
            std::cout << time << std::endl;

            fout.open(filename, std::ios_base::app);
            fout << N << "," << W << "," << std::fixed << std::setprecision(5) << time << "\n";
            fout.close();
        }
    }

    return 0;
}
*/

//正解
int main()
{
    //ファイル削除
    char filename[] = "test_6.csv";
    std::ofstream fout;
    fout.open(filename, std::ios::trunc);
    fout.close();

    //ヘッダー指定
    fout.open(filename, std::ios_base::app);
    fout << "N"
         << ","
         << "W"
         << ","
         << "time[ms]"
         << "\n";
    fout.close();

    for (int N = 1e1; N < 5e2; N++)
    {
        for (int W = 1e1; W < 5e2; W++)
        {
            std::vector<int> a(N), m(N);
            std::vector<std::vector<int>> dp(W + 1, std::vector<int>(N + 1, INF));
            int tmp;

            //値代入
            //std::cout << std::endl;
            for (int i = 0; i < N; i++)
            {
                a[i] = rand() % 10 + 2;
                m[i] = rand() % 10 + 2;
                //std::cout << a[i] << "\t" << m[i] << std::endl;
            }
            std::cout << std::endl;

            clock_t start = clock();

            //初期化
            dp[0][0] = 0;

            //DP
            for (int i = 1; i <= N; i++)
            {
                //コピー
                for (int w = 0; w <= W; w++)
                {
                    if (dp[w][i - 1] != INF)
                    {
                        dp[w][i] = 0;
                    }
                }

                for (int w = 0; w <= W; w++)
                {
                    if (dp[w][i] < m[i] && a[i - 1] + w <= W)
                    {
                        chmin(dp[a[i - 1] + w][i], dp[w][i] + 1);
                    }
                }
            }
            //std::cout << std::endl;

            clock_t end = clock();

            /*
            for (int w = 0; w <= W; w++)
            {
                for (int i = 0; i <= N; i++)
                {
                    if (dp[w][i] == INF)
                    {
                        std::cout << "INF"
                                  << "\t";
                    }
                    else
                    {
                        std::cout << dp[w][i] << "\t";
                    }
                }
                std::cout << std::endl;
            }
            */

            const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
            std::cout << time << std::endl;

            fout.open(filename, std::ios_base::app);
            fout << N << "," << W << "," << std::fixed << std::setprecision(5) << time << "\n";
            fout.close();
        }
    }

    return 0;
}