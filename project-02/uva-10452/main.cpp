#include <iostream>
#include <vector>
using namespace std;
int r, c;
int rows, columns;
bool isPossible(char ch)
{
    return ch == 'I' || ch == 'E' || ch == 'H' || ch == 'O' || ch == 'V' || ch == 'A' || ch == '#';
}
void solve(vector<vector<bool>> &used, vector<string> &solution, vector<vector<char>> &path)
{
    if (path[r][c] == '#')
        return;
    if (isPossible(path[r][c + 1]) && !used[r][c + 1])
    {
        used[r][c + 1] = 1;
        solution.push_back("right");
        c++;
        solve(used, solution, path);
    }
    else if (isPossible(path[r][c - 1]) && !used[r][c - 1])
    {
        used[r][c - 1] = 1;
        solution.push_back("left");
        c--;
        solve(used, solution, path);
    }
    else if (isPossible(path[r - 1][c]) && !used[r - 1][c])
    {
        used[r - 1][c] = 1;
        solution.push_back("forth");
        r--;
        solve(used, solution, path);
    }
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
    }
}