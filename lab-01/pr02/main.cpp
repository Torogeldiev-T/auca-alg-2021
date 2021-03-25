#include <iostream>
#include <list>
using namespace std;
void printInDirectOrder(const list<int> &v)
{
    for (auto e : v)
    {
        cout << " " << e;
    }
    cout << endl;
}
void printInReverseOrder(const list<int> &v)
{
    for (list<int>::const_reverse_iterator p = v.rbegin(); p != v.rend(); p++)
    {
        cout << " " << *p;
    }
    cout << endl;
}
int main()
{
    list<int> v;
    for (int x; cin >> x;)
        v.push_back(x);
    printInDirectOrder(v);
    printInReverseOrder(v);
    for (auto p = v.begin(); p != v.end(); p++)
    {
        if (*p % 2 == 0)
        {
            v.insert(p, 0);
            p++;
        }
    }
    printInDirectOrder(v);
    printInReverseOrder(v);
    for (auto p = v.begin(); p != v.end();)
    {
        if (*p % 2 == 0)
        {
            p = v.erase(p);
        }
        else
            p++;
    }
    printInDirectOrder(v);
    printInReverseOrder(v);
}