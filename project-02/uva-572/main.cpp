#include <iostream>
#include <vector>
using namespace std;
vector<int> dr = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<int> dc = {0, 1, 1, 1, 0, -1, -1, -1};
void dfs(int r, int c, vector<string> &grid)
{
    grid[r][c] = 'p';
    for (int i = 0; i < 8; i++)
    {
        int tr = r + dr[i];
        int tc = c + dc[i];
        if (tr >= 0 && tr < grid.size() && tc >= 0 && tc < grid[0].size() && grid[tr][tc] == '@')
        {
            dfs(tr, tc, grid);
        }
    }
}
int main()
{
    for (int h, w; cin >> h >> w && h + w != 0;)
    {
        vector<string> grid(h);
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        for (int r = 0; r < h; r++)
        {
            cin >> grid[r];
        }
        int res = 0;
        for (int r = 0; r < h; r++)
        {
            for (int c = 0; c < w; c++)
            {
                if (grid[r][c] == '@' && !visited[r][c])
                {
                    dfs(r, c, grid);
                    res++;
                }
            }
        }
        cout << res << endl;
    }
}