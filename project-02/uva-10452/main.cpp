#include <iostream>
#include <vector>
using namespace std;
int r, c;
const int xMoves[] = {-1, 0, 1};
const int yMoves[] = {0, -1, 0};
vector<string> dirs = {"left", "forth", "right"};
string rule = "IEHOVA#";
int idx = 0;
bool isPossible(char ch)
{
    return ch == 'I' || ch == 'E' || ch == 'H' || ch == 'O' || ch == 'V' || ch == 'A' || ch == '#';
}
void solve(vector<vector<bool>> &used, vector<string> &solution, vector<vector<char>> &path)
{
    if (path[r][c] == '#')
        return;
    for (int i = 0; i < 3; i++)
    {
        if (r + yMoves[i] >= 0 && r + yMoves[i] < path.size() && c + xMoves[i] >= 0 && c + xMoves[i] < path[r].size() && path[r + yMoves[i]][c + xMoves[i]] == rule[idx])
        {
            solution.push_back(dirs[i]);
            r += yMoves[i];
            c += xMoves[i];
            idx++;
        }
    }
    solve(used, solution, path);
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int rows, columns;
        cin >> rows >> columns;
        vector<vector<char>> path(rows, vector<char>(columns));
        vector<vector<bool>> used(rows, vector<bool>(columns, 0));
        vector<string> solution;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cin >> path[i][j];
                if (path[i][j] == '@')
                {
                    r = i;
                    c = j;
                }
            }
        }
        solve(used, solution, path);
        for (int i = 0; i < solution.size(); i++)
        {
            cout << solution[i];
            if (i == solution.size() - 1)
            {
                cout << "\n";
            }
            else
            {
                cout << " ";
            }
        }
        idx = 0;
    }
}