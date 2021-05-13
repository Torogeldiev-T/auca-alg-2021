#include <iostream>
#include <cstdint>
using namespace std;
int64_t factorial(int n)
{
    return 0 == n ? 1 : n * factorial(n - 1);
}
int main()
{
    for (int x; cin >> x;)
    {
        cout << x << "! = " << factorial(x) << endl;
    }
}