#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>

void func(int K, int tmp, int bit, int &count)
{
    //ベースケース
    if (tmp > K)
    {
        return;
    }
    if (bit == ((1 << 3) - 1))
    {
        count++;
    }

    //深さ方向探索
    func(K, 10 * tmp + 3, bit | (1 << 0), count);
    func(K, 10 * tmp + 5, bit | (1 << 1), count);
    func(K, 10 * tmp + 7, bit | (1 << 2), count);
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
    fout << "K"
         << ","
         << "time[ms]"
         << "\n";
    fout.close();

    //D桁数
    for (int K = 1e4; K < 1e7; K++)
    {

        int count = 0;

        clock_t start = clock();

        func(K, 0, 0, count);

        std::cout << count << std::endl;

        clock_t end = clock();

        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << K << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}