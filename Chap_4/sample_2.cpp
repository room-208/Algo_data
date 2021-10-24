#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>

int func(int N)
{
    //ベースケース
    if (N == 0)
    {
        std::cout << "start" << std::endl;
        return 0;
    }

    //再帰呼び出し
    std::cout << N << "\t"
              << "func(" << N - 1 << ")" << std::endl;
    return N + func(N - 1);
}

int main()
{
    //ファイル削除
    char filename[] = "data_2.csv";
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

    for (int N = 5; N < 5 + 1; N++)
    {
        clock_t start = clock();

        std::cout << func(N) << std::endl;

        clock_t end = clock();

        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}