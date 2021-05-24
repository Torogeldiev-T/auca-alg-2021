#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;
enum class Color
{

    white,
    red,
    black
};
int main()
{
    string t1;
    getline(cin, t1);
    int n = stoi(t1);
    getline(cin, t1);
    for (int k = 0; k < n; k++)
    {
        map<string, vector<string>> graph;
        vector<string> dict;
        string s;
        while (getline(cin, s) && s != "*")
        {
            dict.push_back(s);
        }
        for (int i = 0; i < dict.size(); i++)
        {
            for (int j = i + 1; j < dict.size(); j++)
            {
                if (dict[i].size() == dict[j].size())
                {
                    graph[dict[i]].push_back(dict[j]);
                    graph[dict[j]].push_back(dict[i]);
                }
            }
        }
        // for (int i = 0; i < dict.size(); i++)
        // {
        //     for (auto e : graph[dict[i]])
        //     {
        //         cout << e << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        string src, dest;
        while (getline(cin, s) && s != "")
        {
            istringstream ss(s);
            ss >> src >> dest;
            map<string, Color> states;
            map<string, int> distances;
            for (auto e : dict)
            {
                states[e] = Color::white;
            }
            queue<string> q;
            q.push(src);
            states[src] = Color::red;
            distances[src] = 0;
            while (!q.empty())
            {
                string u = q.front();
                q.pop();
                states[u] = Color::black;
                for (const auto e : graph[u])
                {
                    int different = 0;
                    for (int i = 0; i < u.size(); i++)
                    {
                        if (u[i] != e[i])
                            different++;
                    }
                    if (states[e] == Color::white && different == 1)
                    {
                        states[e] = Color::red;
                        q.push(e);
                        distances[e] = distances[u] + 1;
                    }
                }
            }
            cout << src << " " << dest << " " << distances[dest] << endl;
        }

        if (k != n - 1)
            cout << "\n";
    }
}
