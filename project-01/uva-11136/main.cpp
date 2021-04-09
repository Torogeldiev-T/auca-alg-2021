#include <set>
#include <iostream>
using namespace std;

int main()
{
    int cases;
    while (cin >> cases && cases != 0)
    {
        multiset<int> s;
        long long res = 0;
        for (int l = 0; l < cases; l++)
        {
            int n;
            cin >> n;
            for (int k = 0; k < n; k++)
            {
                int t;
                cin >> t;
                s.insert(t);
            }
            res += abs(*(--(s.end())) - *(s.begin()));
            s.erase(s.begin());
            s.erase(--s.end());
        }
        cout << res << "\n";
    }
}
