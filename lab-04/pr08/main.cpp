#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
class Solver
{
    struct Frame
    {
        int row;
        int col;
        Frame(int r, int c) : row(r), col(c)
        {
        }
    };

    int mN;
    vector<bool> rows;
    vector<bool> diag1;
    vector<bool> diag2;
    vector<int> solution;

public:
    Solver(int n) : mN(n)
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
            print();
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
            cout << " " << e;
        }
        cout << endl;
    }
    void run()
    {
        vector<Frame> stack;
        stack.emplace_back(0, 0);
        while (!stack.empty())
        {
            if (stack.back().col == mN)
            {
                print();
                stack.pop_back();
                takeQueen(stack.back().row, stack.back().col);
                stack.back().row++;
            }
            else if (stack.back().row == mN)
            {
                stack.pop_back();
                if (!stack.empty())
                {
                    takeQueen(stack.back().row, stack.back().col);
                    stack.back().row++;
                }
            }
            else if (canPutQueen(stack.back().row, stack.back().col))
            {
                putQueen(stack.back().row, stack.back().col);
                stack.emplace_back(0, stack.back().col + 1);
            }
            else
            {
                ++stack.back().row;
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;
    Solver(n).run();
}