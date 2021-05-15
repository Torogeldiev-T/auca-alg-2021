#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
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
    string source, dest;
    cin >> source >> dest;
    map<string, vector<pair<string, int>>> graph;
    {
        string u;
        string v;
        int w;
        while (cin >> u >> v >> w)
        {
            graph[u].emplace_back(v, w);
        }
    }
    map<string, State> states;
    map<string, int> weights;
    map<string, string> preds;

    for (const auto &e : graph)
    {
        states[e.first] = State::NotDefined;
        weights[e.first] = KNotDefined;
    }

    set<pair<int, string>> border;
    states[source] = State::OnBorder;
    weights[source] = 0;
    border.emplace(0, source);
    while (!border.empty())
    {
        auto p = *border.begin();
        border.erase(border.begin());
        string u = p.second;
        states[u] = State::InTree;

        for (const auto &v : graph[u])
        {
            State state = states[v.first];
            if (state == State::NotDefined)
            {
                states[v.first] = State::OnBorder;
                preds[v.first] = u;
                int w = weights[u] + v.second;
                weights[v.first] = w;
                border.emplace(w, v.first);
            }
            else if (state == State::OnBorder)
            {
                int w1 = weights[v.first];
                int w2 = weights[u] + v.second;
                if (w1 > w2)
                {
                    border.erase({w1, v.first});
                    border.emplace(w2, v.first);
                    weights[v.first] = w2;
                    preds[v.first] = u;
                }
            }
        }
    }
    for (const auto &p : weights)
    {
        cout << p.first << ": " << p.second << endl;
    }
    if (weights[dest] == KNotDefined)
    {
        cout << "Unreachable" << endl;
    }
    else
    {
        vector<string> path = {dest};
        while (path.back() != source)
        {
            path.push_back(preds[path.back()]);
        }
        reverse(path.begin(), path.end());
        for (const auto e : path)
        {
            cout << e << " ";
        }
        cout << endl;
        cout << "Total Weight " << weights[dest] << endl;
    }
}