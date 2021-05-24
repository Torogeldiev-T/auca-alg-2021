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

    int n, b = 0;
    while (cin >> n)
    {
        if (b)
            cout << endl;
        map<string, vector<string>> graph;
        map<string, Color> states;
        map<string, string> preds;
        map<string, int> distances;
        for (int i = 0; i < n; i++)
        {
            string v1, v2;
            cin >> v1 >> v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        string src, dest;
        cin >> src >> dest;
        if (graph.find(dest) == graph.end())
        {
            cout << "No route\n";
            continue;
        }
        for (const auto &e : graph)
        {
            states[e.first] = Color::white;
            preds[e.first] = kNil;
        }
        queue<string> q;
        q.push(src);
        distances[src] = 0;
        states[src] = Color::red;
        while (!q.empty())
        {
            string u = q.front();
            q.pop();
            states[u] = Color::black;
            for (const auto e : graph[u])
            {
                if (states[e] == Color::white)
                {
                    states[e] = Color::red;
                    q.push(e);
                    distances[e] = distances[u] + 1;
                    preds[e] = u;
                }
            }
        }
        if (preds[dest] == kNil)
        {
            cout << "No route\n";
        }
        else
        {
            vector<string> path;
            string currVertex = dest;
            while (preds[currVertex] != kNil)
            {
                path.push_back(currVertex);
                path.push_back(preds[currVertex]);
                currVertex = preds[currVertex];
            }

            reverse(path.begin(), path.end());
            int counter = 1;
            for (auto &e : path)
            {
                cout << e;
                if (counter % 2 == 0)
                    cout << endl;
                else
                {
                    cout << " ";
                }
                counter++;
            }
        }
        b = 1;
    }
}