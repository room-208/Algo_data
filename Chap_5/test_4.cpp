#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>

template <class T>
void chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
    }
}

void func(int n, int W, int N, std::vector<int> &a, std::vector<int> &count)
{
    //Wを舐める(countが自分自身とダブらないように、W→0としている)
    for (int i = W; i >= 0; i--)
    {
        if (i - a[n] >= 0)
        {
            if (count[i - a[n]] != -1)
            {
                if (count[i] == -1)
                {
                    count[i] = count[i - a[n]] + 1;
                }
                else
                {
                    chmin(count[i], count[i - a[n]] + 1);
                }
            }
        }
    }

    //ベースケース
    if (n == N - 1)
    {
        return;
    }

    n++;
    func(n, W, N, a, count);
}

int main()
{
    //ファイル削除
    char filename[] = "test_4.csv";
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
        int W = 10;
        int K = 9;
        std::vector<int> a(N);
        std::vector<int> count(W + 1, -1);

        //値代入
        for (int i = 0; i < N; i++)
        {
            a[i] = rand() % 10 + 1;
            //std::cout << a[i] << std::endl;
        }

        //初期化
        count[0] = 0;
        /*
        for (int i = 0; i <= W; i++)
        {
            std::cout << count[i] << std::endl;
        }
        */

        clock_t start = clock();

        func(0, W, N, a, count);

        clock_t end = clock();

        if (count[W] > -1 && count[W] <= K)
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
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}