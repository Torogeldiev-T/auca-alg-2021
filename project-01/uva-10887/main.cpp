#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        int m, n;
        vector<string> s1, s2;
        cin >> m >> n;
        cin.clear();
        cin.ignore();
        for (int j = 0; j < m; j++)
        {
            string s;
            getline(cin, s);
            s1.push_back(s);
        }
        for (int j = 0; j < n; j++)
        {
            string s;
            getline(cin, s);
            s2.push_back(s);
        }
        unordered_set<string> res_set;
        int res = 0;
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                string temp = s1[j] + s2[k];
                if (res_set.insert(temp).second)
                    res++;
            }
        }
        // for (auto j = res_set.begin(); j != res_set.end(); j++)
        // {
        //     cout << *j << "\n";
        // }
        cout << "Case " << i + 1 << ": " << res << "\n";
    }
}