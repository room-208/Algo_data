#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>

int main()
{
    char filename[] = "data_1.csv";
    std::ofstream fout;
    int count;

    //ファイル削除
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

        count = 0;
        for (int i = 0; i < N; i++)
        {
            ++count;
        }

        clock_t end = clock();

        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}