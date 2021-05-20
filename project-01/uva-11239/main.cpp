#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
struct CustomComp
{
    bool operator()(int key_lhs, int key_rhs)
    {
        if (key_lhs > key_rhs)
            return true;
        return false;
    }
};
int main()
{
    string s;
    map<string, int> projects;
    multimap<int, string, CustomComp> res;
    map<string, vector<string>> students;
    string curr;
    while (getline(cin, s) && s != "0")
    {
        if (s == "1")
        {
            for (auto p = students.begin(); p != students.end(); p++)
            {
                bool b = true;
                string project_name = p->second[0];
                for (int i = 0; i < p->second.size(); i++)
                {
                    if (project_name != p->second[i])
                    {
                        b = false;
                        break;
                    }
                }
                if (b)
                {
                    projects[project_name]++;
                }
            }
            for (auto p = projects.begin(); p != projects.end(); p++)
            {
                res.emplace(p->second, p->first);
            }
            for (auto p = res.begin(); p != res.end(); p++)
            {
                cout << p->second << " " << p->first << endl;
            }

            students.clear();
            projects.clear();
        }
        else if (isupper(s[0]))
        {
            projects.emplace(s, 0);
            curr = s;
        }
        else if (islower(s[0]))
        {
            students[s].push_back(curr);
        }
    }
}