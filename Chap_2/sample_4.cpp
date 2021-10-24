#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>

double calc_dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    //ファイル削除
    char filename[] = "data_4.csv";
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

        std::vector<double> x(N),y(N);

        //値代入
        for(int i=0;i<N;i++){
            x[i]=rand()%10+1;
            y[i]=rand()%10+1;
        }

        double min_dist=1e10;
        double dist_tmp;

        for (int i = 0; i < N-1; i++)
        {
            for (int j = i+1; j < N; j++)
            {
                dist_tmp=calc_dist(x[i],y[i],x[j],y[j]);

                if(dist_tmp<min_dist){
                    min_dist=dist_tmp;
                }
            }
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