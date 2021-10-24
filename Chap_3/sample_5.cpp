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
    char filename[] = "data_5.csv";
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

        std::vector<int> a(N);
        int W = 100;
        int tmp;
        bool exist=false;

        //値代入
        for (int i = 0; i < N; i++)
        {
            a[i] = rand() % 100 + 1;
        }


        for (int bit = 0; bit < (1 << N); bit++)
        {
            tmp=0;
            for (int i = 0; i < N; i++)
            {
                if (bit & (1 << i)){
                    tmp+=a[i];
                }
            }

            if(tmp==W){
                exist=true;
                break;
            }
        }

        std::cout << exist << std::endl;

        clock_t end = clock();

        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}