#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int friends;
        cin >> friends;
        //<value, friend's id>
        unordered_map<int, int> maps;
        vector<int> res(friends, 0);
        for (int j = 0; j < friends; j++)
        {
            int stamps;
            cin >> stamps;
            for (int k = 0; k < stamps; k++)
            {
                int value;
                cin >> value;
                auto iter = maps.find(value);
                if (iter != maps.end() && iter->second != j)
                {
                    maps.erase(iter);
                    continue;
                }
                maps.insert({value, j});
            }
        }
        int totalsum = 0;
        for (auto p = maps.begin(); p != maps.end(); p++)
        {
            res[p->second]++;
            totalsum++;
        }
        cout << "Case " << i + 1 << ": ";
        for (int j = 0; j < res.size(); j++)
        {
            float pers = res[j] * 100 / (float)totalsum;
            printf("%.6f", pers);
            if (j != res.size() - 1)
                cout << "% ";
            else
                cout << "%\n";
        }
    }
}