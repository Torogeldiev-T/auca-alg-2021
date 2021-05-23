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
vector<int> dy = {-1, 0, 0, 1};
vector<int> dx = {0, -1, 1, 0};
vector<string> graph;
bool isIn(int y, int x, int dy, int dx)
{
    return x + dx >= 0 && x + dx < graph.size() && y + dy >= 0 && y + dy < graph.size();
}
void dfs(int y, int x, vector<string> &graph, vector<vector<Color>> &colors)
{
    graph[y][x] = '#';
    for (int i = 0; i < dx.size(); i++)
    {
        if (graph[y + dy[i]][x + dx[i]] == ' ')
        {
            dfs(y + dy[i], x + dx[i], graph, colors);
        }
    }
}
int main()
{
    string t1;
    getline(cin, t1);
    int n = stoi(t1);
    for (int k = 0; k < n; k++)
    {
        string s;
        vector<vector<Color>> colors;
        int r = 0, c = 0, t2 = 0;
        while (getline(cin, s) && s[0] != '_')
        {
            graph.push_back(s);
            for (int i = 0; i < graph[t2].size(); i++)
            {
                if (graph[t2][i] == '*')
                {
                    c = i;
                    r = t2;
                }
            }
            colors.push_back(vector<Color>(s.size(), Color::white));
            t2++;
        }
        dfs(r, c, graph, colors);
        for (int i = 0; i < graph.size(); i++)
        {
            cout << graph[i] << endl;
        }
        cout << s << endl;
        graph.clear();
    }
}