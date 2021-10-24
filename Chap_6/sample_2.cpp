#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>

const int M = 10;

bool P(int x)
{
    if (x >= M)
    {
        return true;
    }
    else
    {
        return false;
    }
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
         << "count"
         << "\n";
    fout.close();

    for (int N = 1e1; N < 1e8; N++)
    {
        int count;
        int left, mid, right;

        right = N;
        left = 0;
        count = 0;

        clock_t start = clock();

        while (right - left > 1)
        {
            count++;
            mid = (int)floor(((double)left + (double)right) / 2.);

            if (P(mid))
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        
        clock_t end = clock();

        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        //std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << count << "\n";
        fout.close();
    }

    return 0;
}