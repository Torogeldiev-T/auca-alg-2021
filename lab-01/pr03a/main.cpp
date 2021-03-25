#include <iostream>
#include "List.hpp"
using namespace std;
int main()
{
    List<int> v;
    for (int x; cin >> x;)
    {
        v.pushBack(x);
    }
    cout << v.toStr();
    cout << v.toReversedStr();
    for (auto p = v.begin(); p != v.end(); p++)
    {
        if (*p % 2 == 0)
        {
            v.insert(p, 0);
            p++;
        }
    }
    cout << v.toStr();
    cout << v.toReversedStr();
    for (auto p = v.begin(); p != v.end();)
    {
        if (*p % 2 == 0)
        {
            p = v.erase(p);
        }
        else
            p++;
    }
    cout << v.toStr();
    cout << v.toReversedStr();
}