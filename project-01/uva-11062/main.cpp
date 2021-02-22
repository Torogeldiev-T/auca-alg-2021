#include <iostream>
#include <set>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    set<string> r;
    string finalw = "";
    string w = "";

    for (string s; cin >> s;)
    {
        int b = 0;
        int a = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (isalpha(s[i]))
            {
                w += tolower(s[i]);
            }
            else if (s[i] == '-')
            {
                if (i + 1 >= s.size())
                {
                    b = 1;
                    break;
                }
                else
                {
                    w += s[i];
                }
            }
            else
            {
                r.insert(w);
                w.clear();
                a = 1;
            }
        }
        if (b)
        {
            continue;
        }
        r.insert(w);
        w.clear();
    }
    r.erase("");
    for (auto e : r)
    {
        cout << e << endl;
    }
}