#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    unordered_set<int> s1 = {1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441, 1000000, 1771561, 2985984, 4826809, 7529536, 11390625, 16777216, 24137569, 34012224, 47045881, 64000000, 85766121};
    int n;
    while (cin >> n && n != 0)
    {
        if (s1.find(n) != s1.end())
        {
            cout << "Special\n";
        }
        else
        {
            cout << "Ordinary\n";
        }
    }
}
