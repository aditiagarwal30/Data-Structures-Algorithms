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

    // searching
    cout << m["aditi"] << endl;
    cout << m.at("ayush") << endl;
    // cout << m["shruti"];
    //   cout << m.at("shruti"); // no prev instance of the key

    unordered_map<string, int>::iterator it = m.begin();
    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }
    return 0;
}