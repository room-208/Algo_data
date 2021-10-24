#define _GLIBCXX_DEBUG
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
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bits/stdc++.h>
#include <deque>
#include <queue>
#include <list>

/*
vector<int> a(N);
vector<vector<int>> a(N, vector<int>(N));
auto itr = a.begin();
for (auto itr = a.begin(); itr != a.end(); itr++)
{
    cout << itr - a.begin() << endl; = 0,1,...,N-1
}
sort(a.begin(), a.end());
reverse(a.begin(), a.end());
a.size();
a.empty();
*/

/*
list<int> lst;
lst.push_front(i);
lst.push_back(i);
lst.pop_front();
lst.pop_back();
for(auto itr = lst.begin(); itr != lst.end(); ++itr) {
    std::cout << *itr << "\n";
}
*/

using namespace std;

struct Heap
{
    vector<int> heap;
    Heap() {}

    void push(int x)
    {
        heap.push_back(x);
        int i = heap.size() - 1;
        while (i > 0)
        {
            int p = (i - 1) / 2;
            if (heap[p] >= x)
            {
                break;
            }
            heap[i] = heap[p];
            i = p;
        }
        heap[i] = x;
    }

    int top()
    {
        if (!heap.empty())
        {
            return heap[0];
        }
        else
        {
            return -1;
        }
    }

    int size()
    {
        if (heap.empty())
        {
            return -1;
        }
        else
        {
            return heap.size();
        }
    }

    void pop()
    {
        if (heap.empty())
        {
            return;
        }

        int x = heap.back();
        heap.pop_back();
        int i = 0;

        //左が存在しない
        while (2 * i + 1 < (int)heap.size())
        {
            int child1 = i * 2 + 1, child2 = i * 2 + 2;
            if (child2 < (int)heap.size() && heap[child2] > heap[child1])
            {
                child1 = child2;
            }

            if (heap[child1] <= x)
            {
                break;
            }
            heap[i] = heap[child1];
            i = child1;
        }
        heap[i] = x;
    }
};

int main()
{
    Heap h;
    h.push(5);
    h.push(6);
    h.push(1);
    cout << h.top() << endl;
    h.pop();
    cout << h.top() << endl;
    h.pop();
}
