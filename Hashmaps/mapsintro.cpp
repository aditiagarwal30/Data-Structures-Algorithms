#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    // creation
    unordered_map<string, int> m;

    // insertion

    // 1
    pair<string, int> p = make_pair("aditi", 3);
    m.insert(p);

    // 2
    pair<string, int> p2("rishi", 2);
    m.insert(p2);

    // 3
    m["ayush"] = 1;
    m["ayush"] = 4;

    return 0;
}