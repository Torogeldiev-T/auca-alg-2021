#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int k = 0; k < n; k++)
    {
        int m, N;
        cin >> m >> N;
        vector<int> elv;
        multiset<int> set;
        for (int i = 0; i < m; i++)
        {
            int t;
            cin >> t;
            elv.push_back(t);
        }
        int idx = 0;
        multiset<int>::iterator iter;
        multiset<int>::iterator inserted;
        for (int i = 0; i < N; i++)
        {
            int t;
            cin >> t;

            while (idx < t)
            {
                inserted = set.insert(elv[idx]);
                idx++;
                if (iter._M_node == nullptr)
                    iter = set.begin();
                else if (*inserted < *iter)
                    iter--;
            }
            if (i != 0)
                iter++;
            cout << *iter << endl;
        }
        if (k != n - 1)
            cout << "\n";
    }
}