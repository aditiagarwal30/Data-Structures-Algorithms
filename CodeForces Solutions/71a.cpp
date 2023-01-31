#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    vector<string> ans(n);
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        words.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        int s = words[i].size();
        if (s < 11)
            ans.push_back(words[i]);
        else
        {
            string num = to_string(n - 2);
            string abbr = words[i][0] + num + words[i][s - 1];
            ans.push_back(abbr);
        }
    }
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout << ans[i] << endl;
    }
    return 0;
}