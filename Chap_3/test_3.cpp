#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>
#include <string>

const int INF = 1e5;

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

    for (int N = 3; N < 3 + 1; N++)
    {
        clock_t start = clock();

        std::vector<int> S(N);
        int sum;
        int tmp;

        //値代入
        for (int i = 0; i < N; i++)
        {
            std::cin >> S[i];
            //S[i] = rand() % 10;
            std::cout << S[i];
        }
        std::cout << std::endl;

        sum = 0;
        for (int bit = 0; bit < (1 << (N - 1)); bit++)
        {
            tmp = 0;
            for (int i = 0; i < (N - 1); i++)
            {
                tmp += S[i];

                if (bit & (1 << i))
                {
                    sum += tmp;
                    std::cout << tmp << std::endl;
                    tmp = 0;
                }
                else
                {
                    tmp *= 10;
                }
            }

            tmp += S[N - 1];
            sum += tmp;
            std::cout << tmp << std::endl;
        }

        std::cout << sum << std::endl;

        clock_t end = clock();

        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}