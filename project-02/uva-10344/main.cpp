#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
bool solve(int res, int pos, vector<int> &nubmers)
{
    if (pos == 5)
    {
        return res == 23;
    }
    int num = nubmers[pos];
    return solve(res + num, pos + 1, nubmers) || solve(res - num, pos + 1, nubmers) || solve(res * num, pos + 1, nubmers);
}
int main()
{
    string s;
    while (getline(cin, s) && s != "0 0 0 0 0")
    {
        vector<int> v;
        vector<string> operations = {"+", "-", "*"};
        istringstream ss(s);
        while (ss >> s)
        {
            v.push_back(stoi(s));
        }
        sort(v.begin(), v.end());
        bool b;
        do
        {
            b = solve(v[0], 1, v);
            if (b)
                break;

        } while (next_permutation(v.begin(), v.end()));
        if (b)
        {
            cout << "Possible\n";
        }
        else
        {
            cout << "Impossible\n";
        }
    }
}