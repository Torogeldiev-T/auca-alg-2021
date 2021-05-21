#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int length, int dist, string s)
{
    if (s.size() == length)
    {
        if (!dist)
            cout << s << endl;
        return;
    }
    solve(length, dist, s + '0');
    solve(length, dist - 1, s + '1');
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int N, H;
        cin >> N >> H;
        vector<string> res;
        string s = "";
        solve(N, H, s);
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << endl;
        }
    }
}