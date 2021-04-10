#include <set>
#include <unordered_set>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r, s;
        cin >> l >> r >> s;
        set<int> leju, rony, sujon;
        for (int j = 0; j < l; j++)
        {
            int t;
            cin >> t;
            leju.insert(t);
        }
        for (int j = 0; j < r; j++)
        {
            int t;
            cin >> t;
            rony.insert(t);
        }
        for (int j = 0; j < s; j++)
        {
            int t;
            cin >> t;
            sujon.insert(t);
        }
        vector<vector<int>> v(3, vector<int>(2));
        unordered_set<int> counted;
        for (auto j = leju.begin(); j != leju.end(); j++)
        {
            auto iterr = rony.find(*j);
            auto iters = sujon.find(*j);
            if (iterr == rony.end() && iters == sujon.end())
            {
                v[0][0]++;
            }
            else
            {
                if (iterr == rony.end() ^ iters == sujon.end() && counted.find(*j) == counted.end())
                {
                    iterr == rony.end() ? v[1][1]++ : v[2][1]++;
                    counted.insert(*j);
                }
            }
        }
        for (auto j = rony.begin(); j != rony.end(); j++)
        {
            auto iterl = leju.find(*j);
            auto iters = sujon.find(*j);
            if (iterl == leju.end() && iters == sujon.end())
            {
                v[1][0]++;
            }
            else
            {
                if (iterl == leju.end() ^ iters == sujon.end() && counted.find(*j) == counted.end())
                {
                    iterl == leju.end() ? v[0][1]++ : v[2][1]++;
                    counted.insert(*j);
                }
            }
        }
        for (auto j = sujon.begin(); j != sujon.end(); j++)
        {
            auto iterl = leju.find(*j);
            auto iterr = rony.find(*j);
            if (iterl == leju.end() && iterr == rony.end())
            {
                v[2][0]++;
            }
            else
            {
                if (iterl == leju.end() ^ iterr == rony.end() && counted.find(*j) == counted.end())
                {
                    iterl == leju.end() ? v[0][1]++ : v[1][1]++;
                    counted.insert(*j);
                }
            }
        }
        cout << "Case #" << i + 1 << ":\n";
        printf("%d %d\n%d %d\n%d %d\n", v[0][0], v[0][1], v[1][0], v[1][1], v[2][0], v[2][1]);
    }
}
