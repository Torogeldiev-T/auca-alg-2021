#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
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

    int nEdges;
    cin >> nEdges;
    map<string, vector<string>> graph;
    map<string, Color> states;
    map<string, string> preds;
    map<string, int> distances;
    for (int i = 0; i < nEdges; i++)
    {
        string v1;
        cin >> v1;
        string v2;
        cin >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    string src, dest;
    cin >> src >> dest;

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
    vector<string> path;
    string currVertex = dest;
    while (preds[currVertex] != kNil)
    {
        path.push_back(currVertex);
        currVertex = preds[currVertex];
    }
    path.push_back(src);

    reverse(path.begin(), path.end());
    for (auto &e : path)
    {
        cout << " " << e;
    }
    cout << endl;
}