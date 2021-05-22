#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
vector<string> digits = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
string res[300];
void solve(string rule, int idx, vector<string> dict)
{
    if (idx == rule.size())
    {
        for (int i = 0; i < idx; i++)
        {
            cout << res[i];
        }
        cout << endl;
    }
    else
    {
        if (rule[idx] == '#')
        {
            for (int i = 0; i < dict.size(); i++)
            {
                res[idx] = dict[i];
                solve(rule, idx + 1, dict);
            }
        }
        else
        {
            for (int i = 0; i < digits.size(); i++)
            {
                res[idx] = digits[i];
                solve(rule, idx + 1, dict);
            }
        }
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << "--\n";
        vector<string> dict;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            dict.push_back(s);
        }
        int rules;
        cin >> rules;
        map<string, vector<string>> passwords;
        for (int i = 0; i < rules; i++)
        {
            string s;
            cin >> s;
            passwords.emplace(s, vector<string>(0));
            solve(s, 0, dict);
        }
    }
}