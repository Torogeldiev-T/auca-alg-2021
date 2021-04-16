#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    unordered_map<string, int> map;
    for (int i = 0; i < m; i++)
    {
        string s;
        int v;
        cin >> s >> v;
        map.insert({s, v});
    }
    for (int i = 0; i < n; i++)
    {
        string s;
        int res = 0;
        while (cin >> s && s != ".")
        {
            if (map.find(s) != map.end())
            {
                res += map[s];
            }
        }
        cout << res << endl;
    }
}