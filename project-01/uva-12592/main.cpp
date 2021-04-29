#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cin.clear();
    cin.ignore();
    unordered_map<string, string> slogans;
    for (int i = 0; i < n; i++)
    {
        string first, second;
        getline(cin, first);
        getline(cin, second);
        slogans[first] = second;
    }
    int q;
    cin >> q;
    cin.clear();
    cin.ignore();
    for (int i = 0; i < q; i++)
    {
        string first;
        getline(cin, first);
        cout << slogans[first] << endl;
    }
}