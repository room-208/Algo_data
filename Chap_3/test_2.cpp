#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>

const int INF = 1e5;

int main()
{

    //ファイル削除
    char filename[] = "test_2.csv";
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

    for (int N = 1e2; N < 1e3; N++)
    {
        clock_t start = clock();

        int K = INF;
        int x, y, z;
        int count = 0;
        int K_dum;

        K_dum = std::min(K, N);

        for (x = 0; x <= K_dum; x++)
        {
            for (y = 0; y <= K_dum; y++)
            {
                z = N - x - y;
                if (0 <= z && z <= K)
                {
                    count++;
                }
            }
        }

        std::cout << count << "\n";

        clock_t end = clock();

        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}