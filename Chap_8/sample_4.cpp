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
    struct Node *next;
    std::string name;

    Node(std::string name_ = "") : next(NULL), name(name_) {}
    /*
    Node(std::string name_ = "")
    {
        next = NULL;
        name = name_;
    }
    */
};

/*
void insert(Node *v, Node *p)
{
    Node *tmp;
    tmp->next = p->next;
    p->next = v->next;
    v->next = tmp->next;
}
*/

void insert(Node *v, Node *p)
{
    v->next = p->next;
    p->next = v;
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

    for (int N = 1e1; N < 1e1 + 1; N++)
    {
        /*
        struct Node A;
        struct Node B;

        std::cout << &A.name << std::endl;
        std::cout << &A.next << std::endl;
        std::cout << &B.name << std::endl;
        std::cout << &B.next << std::endl;
        */

        struct Node *nil;
        nil = new Node;
        nil->next = nil;

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
            //std::cout << node->name << "\n";

            node->next = nil->next;
            nil->next = node;
        }

        for (Node *p = nil->next; p != nil; p = p->next)
        {
            std::cout << p->name << std::endl;
        }

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