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
    cin >> n;
    for (int k = 0; k < n; k++)
    {
        int roads, queries;
        cin >> roads >> queries;
        map<string, vector<string>> graph;
        for (int i = 0; i < roads; i++)
        {
            string v1, v2;
            cin >> v1 >> v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        for (int i = 0; i < queries; i++)
        {
            string src, dest;
            cin >> src >> dest;
            map<string, Color> states;
            map<string, string> preds;
            for (const auto &e : graph)
            {
                states[e.first] = Color::white;
                preds[e.first] = kNil;
            }
            queue<string> q;
            q.push(src);
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
                        preds[e] = u;
                    }
                }
            }
            vector<char> path;
            string currVertex = dest;
            while (preds[currVertex] != kNil)
            {
                path.push_back(currVertex[0]);
                currVertex = preds[currVertex];
            }
            path.push_back(src[0]);
            reverse(path.begin(), path.end());
            for (auto &e : path)
            {
                cout << e;
            }
            cout << endl;
        }
        if (k != n - 1)
            cout << endl;
    }
}