#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>
#include <string>

struct Node
{
    struct Node *prev, *next;
    std::string name;

    Node(std::string name_ = "") : prev(NULL), next(NULL), name(name_) {}
};

int main()
{
    //ファイル削除
    char filename[] = "data_6.csv";
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

    for (int N = 1e1; N < 1e1 + 1; N++)
    {
        struct Node *nil;
        nil = new Node;
        nil->next = nil;
        nil->prev = nil;

        std::vector<std::string> names = {"yamamoto",
                                          "watanabe",
                                          "ito",
                                          "takahashi",
                                          "suzuki",
                                          "sato"};

        for (int i = 0; i < (int)names.size(); i++)
        {
            Node *node = new Node;

            node->name = names[i];

            node->next = nil->next;
            node->prev = nil;
            nil->next->prev = node;
            nil->next = node;
        }

        //for (Node *p = nil->prev; p != nil; p = p->prev)
        for (Node *p = nil->next; p != nil; p = p->next)
        {
            std::cout << p->name << std::endl;
        }
        std::cout << std::endl;

        //渡辺発見
        Node *watanabe;
        for (Node *p = nil->next; p != nil; p = p->next)
        {
            if (p->name == "watanabe")
            {
                watanabe = p;
            }
        }

        //std::cout << watanabe->name << std::endl;

        //渡辺削除
        watanabe->prev->next = watanabe->next;
        watanabe->next->prev = watanabe->prev;

        //for (Node *p = nil->prev; p != nil; p = p->prev)
        for (Node *p = nil->next; p != nil; p = p->next)
        {
            std::cout << p->name << std::endl;
        }
        std::cout << std::endl;

        clock_t start = clock();
        clock_t end = clock();
        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}