#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
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
    int n, c = 0;
    while (cin >> n && n != 0)
    {
        map<string, vector<string>> graph;
        for (int i = 0; i < n; i++)
        {
            string v1, v2;
            cin >> v1 >> v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        string src;
        int ttl;
        while (cin >> src >> ttl && stoi(src) + ttl != 0)
        {
            map<string, Color> states;
            map<string, int> distances;
            for (auto e : graph)
            {
                states[e.first] = Color::white;
            }
            queue<string> q;
            q.push(src);
            distances[src] = ttl;
            states[src] = Color::red;
            while (!q.empty())
            {
                string u = q.front();
                q.pop();
                states[u] = Color::black;
                if (distances[u] == 0)
                    continue;
                for (const auto e : graph[u])
                {
                    if (states[e] == Color::white)
                    {
                        states[e] = Color::red;
                        q.push(e);
                        distances[e] = distances[u] - 1;
                    }
                }
            }
            int res = 0;
            for (auto e : states)
            {
                if (e.second == Color::white)
                    res++;
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++c, res, stoi(src), ttl);
        }
    }
}
