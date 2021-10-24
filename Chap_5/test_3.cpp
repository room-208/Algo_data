#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>

void func(int n, int W, int N, std::vector<int> &a, std::vector<bool> &memo)
{
    //Wを舐める
    for (int i = 0; i < W + 1; i++)
    {
        if (i - a[n] >= 0)
        {
            if (memo[i - a[n]] == true)
            {
                memo[i] = true;
            }
        }
    }

    //ベースケース
    if (n == N - 1)
    {
        return;
    }

    n++;
    func(n, W, N, a, memo);
}

int main()
{
    //ファイル削除
    char filename[] = "test_3.csv";
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
        int count = 0;
        std::vector<int> a(N);
        std::vector<bool> memo(W + 1);

        //値代入
        for (int i = 0; i < N; i++)
        {
            a[i] = rand() % 10 + 1;
            //std::cout << a[i] << std::endl;
        }
        //初期化
        memo.assign(W + 1, false);
        memo[0] = true;

        clock_t start = clock();

        func(0, W, N, a, memo);

        clock_t end = clock();

        /*
        std::cout << "\n";
        for (int i = 1; i <= W; i++)
        {
            if (memo[i] == true)
            {
                std::cout << i << "\n";
                count++;
            }
        }
        std::cout << "\n";
        */

        std::cout << count << std::endl;

        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}