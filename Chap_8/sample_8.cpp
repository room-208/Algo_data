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

int main()
{
    /*
    std::unordered_set<int> a;

    a.insert(0);
    a.erase(0);

    std::cout << a.count(0) << std::endl;
    */

    /*
    std::set<int> s;

    // 挿入
    s.insert(1);
    s.insert(0);
    s.insert(2);

    std::cout << s.count(3) << std::endl;
    */

    std::unordered_set<std::string> a;

    a.insert("cat");
    a.insert("dog");

    std::cout << a.count("d") << std::endl;

    return 0;
}