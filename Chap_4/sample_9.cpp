#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>

bool func(int n, int W, std::vector<int> &a)
{
    //ベースケース
    if (n == 0)
    {
        if (W == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //a[n-1]選ぶ
    else if (func(n - 1, W - a[n - 1], a))
    {
        return true;
    }
    //a[n-1]選ばない
    else if (func(n - 1, W, a))
    {
        return true;
    }

    return false;
}

int main()
{
    //ファイル削除
    char filename[] = "data_9.csv";
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
        int W = 10;
        std::vector<int> a(N);

        //値代入
        for (int i = 0; i < N; i++)
        {
            a[i] = rand() % 5 + 1;
            //std::cout << a[i] << std::endl;
        }

        clock_t start = clock();

        std::cout << func(N, W, a) << std::endl;

        clock_t end = clock();

        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}