#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long long number = 1;
int towers;
void solve(int pos, vector<int> prev)
{
    if (pos == towers)
        return;
    int x = sqrt((double)number + (double)prev[pos]);
    if (x * x == (number + prev[pos]) || prev[pos] == 0)
    {
        prev[pos] = number;
        number++;
        pos = 0;
        solve(pos, prev);
    }
    else
    {
        solve(pos + 1, prev);
    }
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        cin >> towers;
        vector<int> prev(towers, 0);
        solve(0, prev);
        cout << number - 1 << endl;
    }
}