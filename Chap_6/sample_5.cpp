#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>

const int INF = 1 << 30;

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

    for (int N = 1e1; N < 1e5; N++)
    {
        std::vector<int> H(N), S(N);
        std::vector<double> dt(N);
        int tmp;
        int x_l, x_m, x_r;
        int M;
        bool flag;

        for (int i = 0; i < N; i++)
        {
            H[i] = rand() % 10 + 1;
            S[i] = rand() % 10 + 1;
            //std::cout << a[i] << "\t" << b[i] << std::endl;
        }

        clock_t start = clock();

        //安全エリア計算O(N)
        M = 0;
        for (int i = 0; i < N; i++)
        {
            tmp = H[i] + S[i] * N;
            if (M < tmp)
            {
                M = tmp;
            }
        }

        //初期値
        x_r = M;
        x_l = 0;
        //ループO(M)
        while (x_r - x_l > 1)
        {
            flag = true;

            x_m = (int)floor(((double)x_l + (double)x_r) / 2.);

            //時間計算O(N)
            for (int i = 0; i < N; i++)
            {
                dt[i] = ((double)x_m - (double)H[i]) / (double)S[i];
                if (dt[i] < 0.)
                {
                    flag = false;
                }
            }

            //ソートO(NlogN)
            std::sort(dt.begin(), dt.end());

            //シミュレーションO(N)
            for (int i = 0; i < N; i++)
            {
                if (dt[i] < (double)i)
                {
                    flag = false;
                }
            }

            if (flag)
            {
                x_r = x_m;
            }
            else
            {
                x_l = x_m;
            }
        }

        clock_t end = clock();

        std::cout << x_r << std::endl;
        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}