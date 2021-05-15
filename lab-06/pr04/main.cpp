#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
const int kNoPred = -1;
enum class Color
{
    white,
    red,
    black
};
bool inside(const vector<string> &maze, int r, int c)
{
    int h = maze.size();
    int w = maze[0].size();
    return r >= 0 && r < h && c >= 0 && c < w;
}
int main()
{
    int mazeSize;
    cin >> mazeSize;
    vector<string> maze(mazeSize);
    int start;
    int dest;
    for (int r = 0; r < mazeSize; r++)
    {
        cin >> maze[r];
        int cStart = maze[r].find('S');
        if (cStart != int(string::npos))
        {
            start = r * mazeSize + cStart;
        }
        int cDest = maze[r].find('D');
        if (cDest != int(string::npos))
        {
            dest = r * mazeSize + cDest;
        }
    }
    vector<Color> colors(mazeSize * mazeSize, Color::white);
    vector<int> distances(mazeSize * mazeSize);
    vector<int> preds(mazeSize * mazeSize, kNoPred);
    queue<int> q;

    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    q.push(start);
    colors[start] = Color::red;
    distances[start] = 0;
    colors[start] = Color::black;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        int r = cur / mazeSize;
        int c = cur % mazeSize;
        for (int i = 0; i < int(dr.size()); i++)
        {
            int tr = r + dr[i];
            int tc = c + dc[i];
            int t = tr * mazeSize + tc;
            if (inside(maze, tr, tc) && maze[tr][tc] != '#' && colors[t] == Color::white)
            {
                q.push(t);
                colors[t] = Color::red;
                distances[t] = distances[cur] + 1;
                preds[t] = cur;
                if (t == dest)
                {
                    goto breakForWhile;
                }
            }
        }
    }
breakForWhile:
    if (preds[dest] == kNoPred)
    {
        cout << "Unreachable\n";
    }
    else
    {
        cout << distances[dest] << endl;
        int cur = dest;
        while (cur != start)
        {
            maze[cur / mazeSize][cur % mazeSize] = '*';
            cur = preds[cur];
        }
        for (const auto &e : maze)
        {
            cout << e << endl;
        }
    }
}