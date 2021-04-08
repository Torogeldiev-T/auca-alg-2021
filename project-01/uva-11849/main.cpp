#include <iostream>
#include <unordered_set>

using namespace std;
int main()
{
    int n, m;
    while (cin >> n && cin >> m && n + m != 0)
    {
        unordered_set<int> s1;
        unordered_set<int> s2;
        for (int j = 0; j < n; j++)
        {
            int t;
            cin >> t;
            s1.insert(t);
        }
        int res = 0;
        for (int j = 0; j < m; j++)
        {
            int t;
            cin >> t;
            s2.insert(t);
            if (s1.find(t) != s1.end())
            {
                res++;
            }
        }
        cout << res << "\n";
    }
}