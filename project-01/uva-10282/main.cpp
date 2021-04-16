#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
using namespace std;
int main()
{
    string s;
    string foreign;
    unordered_map<string, string> dic;
    while (getline(cin, s) && !s.empty())
    {
        istringstream ss(s);
        vector<string> v;
        while (ss >> s)
        {
            v.push_back(s);
        }
        dic.insert({v[1], v[0]});
    }
    while (cin >> foreign)
    {
        auto iter = dic.find(foreign);
        if (iter != dic.end())
        {
            cout << dic[foreign] << endl;
        }
        else
        {
            cout << "eh\n";
        }
    }
}