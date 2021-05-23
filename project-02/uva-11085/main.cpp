#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
class Solver
{
    int mN;
    vector<bool> rows;
    vector<bool> diag1;
    vector<bool> diag2;
    vector<int> solution;

public:
    vector<int> state;
    int res = 10;
    Solver(int n, vector<int> &s) : mN(n), state(s)
    {
        if (n < 1)
        {
            throw runtime_error("Incorrect size of puzzle\n");
        }
        rows.resize(n, false);
        diag1.resize(2 * n - 1, false);
        diag2.resize(2 * n - 1, false);
        solution.resize(n);
    }
    void solve(int col)
    {
        if (col == mN)
        {
            int min = 0;
            for (int i = 0; i < solution.size(); i++)
            {
                if ((solution[i] + 1 != state[i]))
                    min++;
            }
            if (res > min)
            {
                res = min;
            }
        }
        else
        {
            for (int row = 0; row < mN; ++row)
            {
                if (canPutQueen(row, col))
                {
                    putQueen(row, col);
                    solve(col + 1);
                    takeQueen(row, col);
                }
            }
        }
    }
    bool canPutQueen(int row, int col)
    {
        return !rows[row] && !diag1[row + col] && !diag2[col - row + mN - 1];
    }
    void putQueen(int row, int col)
    {
        rows[row] = diag1[row + col] = diag2[col - row + mN - 1] = true;
        solution[col] = row;
    }
    void takeQueen(int row, int col)
    {
        rows[row] = diag1[row + col] = diag2[col - row + mN - 1] = false;
    }
    void print()
    {
        for (auto e : solution)
        {
            cout << " " << e + 1;
        }
        cout << endl;
    }
    void run()
    {
        solve(0);
    }
};

int main()
{
    int n;
    int c = 0;
    while (cin >> n)
    {
        vector<int> state(8);
        state[0] = n;
        for (int i = 1; i < 8; i++)
        {
            cin >> state[i];
        }
        Solver s = Solver(8, state);
        s.run();
        printf("Case %d: %d\n", ++c, s.res);
    }
}