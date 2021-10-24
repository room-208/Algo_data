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

using namespace std;

const int MAX = 3;

int qu[MAX];
int tail = 0;
int head = 0;

void init()
{
    head = 0;
    tail = 0;
}

bool isEmpty()
{
    return (tail == head);
}

bool isFull()
{
    return (head == (tail + 1) % MAX);
}

void enqueue(int x)
{
    if (isFull())
    {
        cout << "error" << endl;
        return;
    }

    qu[tail] = x;
    tail++;
    if (tail == MAX)
    {
        tail = 0;
    }
}

int dequeue()
{
    if (isEmpty())
    {
        cout << "error" << endl;
        return -1;
    }

    int res = qu[head];
    head++;
    if (head == MAX)
    {
        head = 0;
    }
    return res;
}

int main()
{
    init();
    
    enqueue(4);
    enqueue(5);

    cout << dequeue() << endl;
    cout << dequeue() << endl;

    return 0;
}