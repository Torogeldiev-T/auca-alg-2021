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
int res = 0;
void dfs(int v, const vector<vector<int>> &graph, vector<Color> &colors)
{
    colors[v] = Color::red;
    res++;
    for (auto e : graph[v])
    {
        if (colors[e] == Color::white)
        {
            dfs(e, graph, colors);
        }
    }
    colors[v] = Color::black;
}
int main()
{
    int cases;
    cin >> cases;
    for (int k = 0; k < cases; k++)
    {
        int m, n, l;
        cin >> m >> n >> l;
        vector<vector<int>> graph(m);
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            graph[x - 1].push_back(y - 1);
        }
        vector<Color> colors(m, Color::white);
        for (int i = 0; i < l; i++)
        {
            int fallen;
            cin >> fallen;
            if (colors[fallen - 1] == Color::white)
                dfs(fallen - 1, graph, colors);
        }
        cout << res << endl;
        res = 0;
    }
}