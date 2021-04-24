#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<int> v;
        int max = 0;
        for (int j = 0; j < m; j++)
        {
            int sf;
            cin >> sf;
            v.push_back(sf);
        }
        for (int j = 0; j < v.size(); j++)
        {
            int curr = 0;
            unordered_map<int, int> temp;
            for (int k = j; k < v.size(); k++)
            {
                auto p = temp.find(v[k]);
                if (p != temp.end())
                {
                    j = p->second;
                    break;
                }
                curr++;
                temp.insert({v[k], k});
            }
            if (max < curr)
            {
                max = curr;
            }
        }
        printf("%d\n", max);
    }
}