#include <iostream>
#include <vector>
using namespace std;

class Solver
{
    int minutes;
    vector<int> result;
    int duration;

public:
    Solver(int m)
        : minutes(m), duration(0)
    {
        result.resize(m);
    }

    void solve(size_t c, int sum, vector<int> &durations, vector<int> &combination)
    {
        if (c == durations.size())
        {
            if (sum <= minutes && sum > duration)
            {
                duration = sum;

                result = combination;
            }
        }
        else
        {
            combination[c] = 0;
            solve(c + 1, sum, durations, combination);
            combination[c] = 1;
            solve(c + 1, sum + durations[c], durations, combination);
        }
    }

    void print(vector<int> &durations)
    {
        for (int i = 0; i < result.size(); ++i)
        {
            if (result[i] == 1)
            {
                cout << durations[i] << " ";
            }
        }
        cout << "sum:" << duration << "\n";
    }
};

int main()
{
    for (int d, n; cin >> d >> n;)
    {
        vector<int> durations(n);
        for (auto &e : durations)
        {
            cin >> e;
        }
        vector<int> combination(n);
        Solver x(d);
        x.solve(0, 0, durations, combination);
        x.print(durations);
    }
}