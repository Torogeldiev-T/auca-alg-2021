#include <iostream>
#include <string>
#include "MapStrInt.hpp"
using namespace std;
int main()
{
    MapStrInt m;
    string s;
    while (cin >> s)
    {
        ++m[s];
    }
    m.printInOrder(cout);
    cout << "Size " << m.size() << endl;
}