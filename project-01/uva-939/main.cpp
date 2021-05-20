#include <iostream>
#include <map>
using namespace std;
void solve(map<string, tuple<string, string, string>> &generations, string name)
{
    auto p = generations[name];
    string parent1 = get<0>(p);
    string parent2 = get<1>(p);
    if (parent1 == "" && parent2 == "")
    {
        return;
    }
    else
    {
        if (get<2>(generations[parent1]) == "")
            solve(generations, parent1);
        if (get<2>(generations[parent2]) == "")
            solve(generations, parent2);
        bool b = true;
        if ((get<2>(generations[parent1]) == "dominant" && get<2>(generations[parent2]) == "dominant") || (get<2>(generations[parent1]) == "recessive" && get<2>(generations[parent2]) == "dominant") || (get<2>(generations[parent1]) == "dominant" && get<2>(generations[parent2]) == "recessive"))
        {
            get<2>(generations[name]) = "dominant";
        }
        else if ((get<2>(generations[parent1]) == "dominant" || get<2>(generations[parent2]) == "dominant") || (get<2>(generations[parent1]) != "non-existent" && get<2>(generations[parent2]) != "non-existent"))
        {
            get<2>(generations[name]) = "recessive";
        }
        else
        {
            get<2>(generations[name]) = "non-existent";
        }
    }
}
int main()
{
    int n;
    cin >> n;
    // name, parent1, parent2, gene
    map<string, tuple<string, string, string>> generations;
    for (int k = 0; k < n; k++)
    {
        string name, s;
        cin >> name >> s;
        if (s == "non-existent" || s == "recessive" || s == "dominant")
        {
            generations[name] = {"", "", s};
        }
        else
        {
            if (generations.find(s) == generations.end())
                generations[s] = {name, "", ""};
            else
                get<1>(generations[s]) = name;
        }
    }
    for (auto p = generations.begin(); p != generations.end(); p++)
    {
        solve(generations, p->first);
        cout << p->first << " " << get<2>(p->second) << endl;
    }
}