#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>

int fibo(int N)
{
    //ベースケース
    if (N == 0)
    {
        std::cout << "start0" << std::endl;
        return 0;
    }
    else if (N == 1)
    {
        std::cout << "start1" << std::endl;
        return 1;
    }

    //再帰呼び出し
    std::cout << "fibo(" << N - 1 << ")\t"
              << "fibo(" << N - 2 << ")" << std::endl;
    return fibo(N - 1) + fibo(N - 2);
}

int main()
{
    //ファイル削除
    char filename[] = "data_6.csv";
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

    for (int N = 1e1; N < 1e2; N++)
    {
        clock_t start = clock();

        std::cout << fibo(N) << std::endl;

        clock_t end = clock();

        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}