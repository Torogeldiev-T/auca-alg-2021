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
void dfs(int v, vector<vector<int>> &graph, vector<Color> &colors)
{
    colors[v] = Color::red;
    for (int e : graph[v])
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
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string s;
        char c;
        cin >> c;
        cin.ignore();
        vector<vector<int>> graph(c - 'A' + 1);
        while (getline(cin, s) && s != "")
        {
            graph[s[0] - 'A'].push_back(s[1] - 'A');
            graph[s[1] - 'A'].push_back(s[0] - 'A');
        }
        int nComponents = 0;
        vector<Color> colors(graph.size(), Color::white);
        for (int i = 0; i != graph.size(); i++)
        {
            if (colors[i] == Color::white)
            {
                ++nComponents;
                dfs(i, graph, colors);
            }
        }
        cout << nComponents << endl;
        if (n != 0)
            cout << "\n";
    }
}