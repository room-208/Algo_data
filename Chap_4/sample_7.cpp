#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>

long long fibo(int n, std::vector<long long> &memo)
{
    //ベースケース
    if (n == 0)
    {
        memo[n] = 0;
        return 0;
    }
    else if (n == 1)
    {
        memo[n] = 1;
        return 1;
    }
    else if (memo[n] != -1)
    {
        return memo[n];
    }
    else
    {
        memo[n] = fibo(n - 1, memo) + fibo(n - 2, memo);
        return memo[n];
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

    for (int N = 1e1; N < 1e5; N++)
    {
        //メモ
        std::vector<long long> memo(N);

        //初期化
        memo.assign(N, -1);

        clock_t start = clock();

        std::cout << fibo(N - 1, memo) << std::endl;

        clock_t end = clock();

        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}