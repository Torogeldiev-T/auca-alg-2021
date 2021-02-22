#include <iostream>
#include <set>
#include <cctype>
#include <string>
using namespace std;
int main()
{
    string w;
    set<string> r;
    for (char c; cin.get(c);)
    {
        if (isalpha(c))
        {
            w += tolower(c);
        }
        else if (!w.empty())
        {
            r.insert(w);
            w.clear();
        }
    }
    if (!w.empty())
    {
        r.insert(w);
    }
    for (const auto &e : r)
    {
        cout << e << endl;
    }
}