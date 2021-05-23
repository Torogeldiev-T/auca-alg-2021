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
    int m, n;
    while (cin >> m >> n && m + n != 0)
    {
        vector<vector<int>> graph(m);
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            graph[x - 1].push_back(y - 1);
        }
        vector<int> order;
        vector<Color> colors(m, Color::white);
        for (int i = 0; i < m; i++)
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
}
