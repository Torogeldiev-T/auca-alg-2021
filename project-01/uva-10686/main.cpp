#include <iostream>
#include <unordered_map>
#include <sstream>
#include <utility>
#include <set>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int catrs;
        cin >> catrs;
        //map <keyword, pair<category name, occured>>
        unordered_multimap<string, tuple<string, int, int>> curr;
        //map <name of category, required number of occasions>
        unordered_map<int, pair<int, string>> req;
        unordered_map<int, pair<int, string>> res;
        for (int i = 0; i < catrs; i++)
        {
            string category;
            int w, r;
            cin >> category >> w >> r;
            req.insert({i, {r, category}});
            res.insert({i, {0, category}});
            while (w--)
            {
                string word;
                cin >> word;
                curr.insert({word, {category, 1, i}});
            }
        }
        string s;
        cin.ignore(100, '\n');
        while (getline(cin, s) && !s.empty())
        {
            for (int j = 0; j < s.size(); j++)
            {
                if (!isalpha(s[j]))
                {
                    s[j] = ' ';
                }
            }
            istringstream ss(s);
            while (ss >> s)
            {
                auto p = curr.equal_range(s);
                set<string> visited;
                while (p.first != p.second)
                {
                    if (get<1>(p.first->second) != 0 && visited.find(get<0>(p.first->second)) == visited.end())
                    {
                        res[get<2>(p.first->second)].first++;
                        get<1>(p.first->second) = 0;
                        visited.insert(get<0>(p.first->second));
                    }
                    p.first++;
                }
            }
        }
        bool b = true, isfirst = true;
        for (int i = 0; i < res.size(); i++)
        {
            if (res[i].first >= req[i].first)
            {
                if (!b)
                {
                    cout << ",";
                }
                cout << req[i].second;
                b = false;
            }
        }
        if (b)
        {
            cout << "SQF Problem." << endl;
        }
        else
        {
            cout << endl;
        }
    }
}