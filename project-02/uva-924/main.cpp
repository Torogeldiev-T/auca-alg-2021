#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <sstream>
using namespace std;
const string kNil = "unknown";
enum class Color
{

    white,
    red,
    black
};
int main()
{
    int n;
    while (cin >> n)
    {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++)
        {
            int friends;
            cin >> friends;
            for (int j = 0; j < friends; j++)
            {
                int fr;
                cin >> fr;
                graph[i].push_back(fr);
            }
        }
        int sources;
        cin >> sources;
        for (int i = 0; i < sources; i++)
        {
            int src;
            cin >> src;
            if (graph[src].size() == 0)
            {
                cout << 0 << endl;
            }
            else
            {
                vector<Color> states(n, Color::white);
                map<int, int> distances;
                map<int, int> employes;
                int boom_size = 0, boom_day = 0;
                queue<int> q;
                q.push(src);
                distances[src] = 0;
                states[src] = Color::red;
                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    states[u] = Color::black;
                    for (const auto e : graph[u])
                    {
                        if (states[e] == Color::white)
                        {
                            states[e] = Color::red;
                            q.push(e);
                            distances[e] = distances[u] + 1;
                            employes[distances[e]]++;
                        }
                    }
                }
                for (auto e : employes)
                {
                    if (boom_size < e.second)
                    {
                        boom_size = e.second;
                        boom_day = e.first;
                    }
                }
                cout << boom_size << " " << boom_day << endl;
            }
        }
    }
}