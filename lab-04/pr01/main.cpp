#include <iostream>
using namespace std;

void ReadAndPrintInReverseOrder()
{
    int x;
    if (cin >> x)
    {
        ReadAndPrintInReverseOrder();
        cout << ' ' << x;
    }
}
int main()
{
    ReadAndPrintInReverseOrder();
    cout << endl;
}