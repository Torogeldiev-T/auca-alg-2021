#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        unordered_map<string, int> m;
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> v;
            for (int j = 0; j < 5; j++)
            {
                int id;
                cin >> id;
                v.push_back(id);
            };
            sort(v.begin(), v.end());
            string frosh = "";
            for (int j = 0; j < v.size(); j++)
            {
                frosh += v[j];
            }
            if (m.find(frosh) == m.end())
            {
                m.insert({frosh, 1});
            }
            else
            {
                m[frosh]++;
            }
            if (m[frosh] > max)
            {
                max = m[frosh];
            }
        }
        int res = 0;
        for (auto p = m.begin(); p != m.end(); p++)
        {
            if (p->second >= max)
                res += p->second;
        }
        cout << res << endl;
    }
}