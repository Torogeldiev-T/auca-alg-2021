#include <iostream>
#include <vector>
#include <cstdint>
#include <sstream>
#include <algorithm>
using namespace std;
enum class Color
{
    white,
    red,
    black

};
void dfs(int v, const vector<vector<int>> &graph, vector<Color> &colors, vector<int> &order)
{
    colors[v] = Color::red;
    for (auto e : graph[v])
    {
        if (colors[e] == Color::white)
        {
            dfs(e, graph, colors, order);
        }
    }
    order.push_back(v);
    colors[v] = Color::black;
}
int main()
{
    string line;
    getline(cin, line);
    int nVertices = stoi(line);
    vector<vector<int>> graph(nVertices);
    for (int i = 0; i < nVertices; i++)
    {
        getline(cin, line);
        if (line != "-")
        {
            istringstream ss(line);
            for (int v; ss >> v;)
            {
                graph[i].push_back(v - 1);
            }
        }
    }
    vector<int> order;
    vector<Color> colors(nVertices, Color::white);
    for (size_t i = 0; i < nVertices; i++)
    {
        if (colors[i] == Color::white)
        {

            dfs(i, graph, colors, order);
        }
    }
    reverse(order.begin(), order.end());
    for (auto e : order)
    {
        cout << " " << e + 1;
    }
    cout << endl;
}