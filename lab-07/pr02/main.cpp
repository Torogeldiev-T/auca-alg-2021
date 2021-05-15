#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;
const int KNotDefined = -1;
enum class State
{
    NotDefined,
    OnBorder,
    InTree,
};
int main()
{
    int nVertices;
    cin >> nVertices;
    vector<vector<pair<int, int>>> graph(nVertices);
    char c1;
    char c2;
    int w;
    while (cin >> c1 >> c2 >> w)
    {
        int u = c1 - 'a';
        int v = c2 - 'a';
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    vector<State> states(nVertices, State::NotDefined);
    vector<int> distances(nVertices, KNotDefined);
    vector<int> preds(nVertices, KNotDefined);
    set<pair<int, int>> border;
    int totalWeight = 0;
    states[0] = State::InTree;

    for (auto v : graph[0])
    {
        states[v.first] = State::OnBorder;
        distances[v.first] = v.second;
        preds[v.first] = 0;
        border.emplace(v.second, v.first);
    }
    for (int i = 1; i < nVertices; i++)
    {
        auto p = *border.begin();
        border.erase(border.begin());

        int u = preds[p.second];
        int v = p.second;
        int w = distances[v];

        cout << char(u + 'a') << " " << char(v + 'a') << " " << w << endl;

        totalWeight += w;

        states[v] = State::InTree;

        for (auto e : graph[v])
        {
            if (states[e.first] == State::NotDefined)
            {
                states[e.first] = State::OnBorder;
                distances[e.first] = e.second;
                preds[e.first] = v;
                border.emplace(e.second, e.first);
            }
            else if (states[e.first] == State::OnBorder && e.second < distances[e.first])
            {
                border.erase({distances[e.first], e.first});
                border.emplace(e.second, e.first);
                distances[e.first] = e.second;
                preds[e.first] = v;
            }
        }
    }
    cout << "Total Weight " << totalWeight << endl;
}