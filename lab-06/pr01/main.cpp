#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
enum class Color
{
    white,
    red,
    black

};
void dfs(int v, const vector<vector<int>> &graph, vector<Color> &colors, vector<int> &component)
{
    colors[v] = Color::red;
    component.push_back(v);
    for (auto e : graph[v])
    {
        if (colors[e] == Color::white)
        {
            dfs(e, graph, colors, component);
        }
    }
    colors[v] = Color::black;
}
int main()
{
    int nVertices;
    cin >> nVertices;
    vector<vector<int>> graph(nVertices);
    for (int r = 0; r < nVertices; r++)
    {
        for (int c = 0; c < nVertices; c++)
        {
            char ch;
            cin >> ch;
            if (ch == '1')
            {
                graph[r].push_back(c);
            }
        }
    }
    int nComponents = 0;
    vector<Color> colors(nVertices, Color::white);
    for (size_t i = 0; i < nVertices; i++)
    {
        if (colors[i] == Color::white)
        {
            ++nComponents;
            vector<int> currComponent;
            dfs(i, graph, colors, currComponent);
            cout << nComponents << ": ";
            for (auto e : currComponent)
            {
                cout << e << " ";
            }
            cout << endl;
        }
    }
}