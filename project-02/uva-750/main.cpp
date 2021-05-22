#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
class Solver
{
    int mN;
    int posr;
    int posc;
    int counter = 0;
    vector<bool> rows;
    vector<bool> diag1;
    vector<bool> diag2;
    vector<int> solution;

public:
    Solver(int n, int r, int c) : mN(n), posr(r), posc(c)
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
            if (solution[posc - 1] == posr - 1)
            {
                counter++;
                print();
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
        if (counter < 10)
            cout << " ";
        cout << counter << "     ";
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
    int n, b = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (b)
            cout << endl;
        int r, c;
        cin >> r >> c;
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        Solver(8, r, c).run();
        b = 1;
    }
}