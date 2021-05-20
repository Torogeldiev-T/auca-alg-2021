#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int k = 0; k < n; k++)
    {
        int m, n;
        unordered_multiset<int> s1, s2;
        cin >> m >> n;
        for (int i = 0; i < m; i++)
        {
            int t;
            cin >> t;
            s1.insert(t);
        }
        int res = 0;
        // unordered_set<int> removed;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            s2.insert(t);
        }
        for (auto i = s1.begin(); i != s1.end(); i++)
        {
            auto p = s2.find(*i);
            if (p == s2.end())
            {
                res++;
            }
            else
            {
                int counter1 = 0;
                int counter2 = 0;
                auto pair1 = s1.equal_range(*i);
                auto pair2 = s2.equal_range(*i);
                while (pair1.first != pair1.second)
                {
                    counter1++;
                    i = pair1.first;
                    pair1.first++;
                }

                while (pair2.first != pair2.second)
                {
                    counter2++;
                    pair2.first++;
                }
                if (counter1 != counter2)
                    res += abs(counter1 - counter2);
            }
        }
        for (auto i = s2.begin(); i != s2.end(); i++)
        {
            auto p = s1.find(*i);
            if (p == s1.end())
            {
                res++;
            }
        }
        cout << res << "\n";
    }
}
