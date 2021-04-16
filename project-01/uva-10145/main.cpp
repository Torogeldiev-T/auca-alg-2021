#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string mode;
        int trans, data;
        unordered_multimap<int, tuple<string, int, bool>> m;
        unordered_map<int, bool> ignored;
        while (true)
        {
            cin >> mode;
            if (mode == "#")
                break;
            cin >> trans >> data;
            auto iter = m.find(data);
            //check if element doesnt exist in map
            if (iter == m.end())
            {
                //check if its  empty
                if (!m.empty())
                {
                    //if trans is blocked then print ignored
                    if (ignored.find(trans) != ignored.end())
                    {
                        cout << "IGNORED\n";
                    }
                    //print granted otherwise
                    else
                    {
                        cout << "GRANTED\n";
                        m.insert({data, {mode, trans, true}});
                    }
                }
                //insert first element
                else
                {
                    m.insert({data, {mode, trans, true}});
                    cout << "GRANTED\n";
                }
            }
            else
            {
                if (ignored.find(trans) != ignored.end())
                {
                    cout << "IGNORED\n";
                    continue;
                }
                auto p = m.equal_range(data);
                bool b = true;
                //check if it conflicts or not
                while (p.first != p.second)
                {
                    if (get<1>(p.first->second) != trans && (get<0>(p.first->second) == "X" || mode == "X"))
                    {
                        cout << "DENIED\n";
                        ignored.insert({trans, false});
                        b = false;
                        break;
                    }
                    p.first++;
                }
                if (b)
                {
                    cout << "GRANTED\n";
                    m.insert({data, {mode, trans, true}});
                }
            }
        }
        m.clear();
        if (n != 0)
            cout << endl;
    }
}
