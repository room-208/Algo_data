#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>

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


    for (int N = 1e2; N < 1e4; N++)
    {
        clock_t start = clock();

        std::vector<int> a(N);
        bool exist = false;
        int v=50;
        int found_id=-1;

        //値代入
        for(int i=0;i<N;i++){
            a[i]=rand()%100+1;
        }        
        
        for (int i = 0; i < N-1; i++)
        {
            if(a[i]==v){
                exist=true;
                found_id=i;
                break;
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