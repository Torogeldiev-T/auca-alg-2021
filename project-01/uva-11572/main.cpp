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
        unordered_map<int, int> maps;
        int maxv = 0, curr = 0, counter = 0, maxpack = 0;
        for (int j = 1; j <= m; j++)
        {
            int sf;
            cin >> sf;
            int seen = maps[sf];

            if (seen)
            {
                maxv = max(maxv, seen);
                counter = j - maxv - 1;
            }

            counter++;
            maps[sf] = j;
            maxpack = max(maxpack, counter);
        }
        printf("%d\n", maxpack);
    }
}