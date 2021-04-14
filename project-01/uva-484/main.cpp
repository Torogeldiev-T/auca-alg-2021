#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main()
{
    int n;
    unordered_map<int, int> m;
    vector<int> v;
    unordered_map<int, int>::iterator prev;

    while (cin >> n)
    {
        auto iter = m.insert({n, 1});
        if (iter.second)
        {
            v.push_back(n);
        }
        else
        {
            iter.first->second++;
        }
    }
    for (auto i = 0; i != v.size(); i++)
    {
        auto iter = m.find(v[i]);
        cout << iter->first << " " << iter->second << endl;
        // cout << iter->first << " " << iter->second << endl;
    }
}
