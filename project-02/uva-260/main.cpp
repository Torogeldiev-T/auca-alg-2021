#include <iostream>
#include <vector>
#include <map>
using namespace std;
enum class Color
{
    white,
    red,
    black

};
vector<int> dy = {-1, -1, 0, 0, 1, 1};
vector<int> dx = {-1, 0, -1, 1, 0, 1};
vector<string> graph;
int isblack;
bool isIn(int x, int y, int dx, int dy)
{
    return x + dx >= 0 && x + dx < graph.size() && y + dy >= 0 && y + dy < graph.size();
}
void dfs(int x, int y, vector<string> &graph, vector<vector<Color>> &colors)
{
    colors[y][x] = Color::red;

    if (y == graph.size() - 1)
    {
        isblack = true;
    }
    for (int i = 0; i < dx.size(); i++)
    {
        if (isIn(x, y, dx[i], dy[i]) && colors[y + dy[i]][x + dx[i]] == Color::white && graph[y + dy[i]][x + dx[i]] == 'b')
        {
            dfs(x + dx[i], y + dy[i], graph, colors);
        }
    }
    colors[y][x] = Color::black;
}
int main()
{
    int n, c = 0;
    while (cin >> n && n != 0)
    {
        isblack = false;
        graph.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> graph[i];
        }
        vector<vector<Color>> colors(n, vector<Color>(n, Color::white));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (colors[i][j] == Color::white && graph[i][j] == 'b' && i == 0)
                {
                    dfs(j, i, graph, colors);
                }
            }
        }
        cout << ++c << " ";
        if (isblack)
        {
            cout << 'B' << endl;
        }
        else
        {
            cout << 'W' << endl;
        }
    }
}