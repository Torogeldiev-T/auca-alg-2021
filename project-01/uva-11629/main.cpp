#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    unordered_map<string, double> parties;
    for (int i = 0; i < m; i++)
    {
        string name;
        double votes;
        int beforeDec, afterDec;
        char dec;
        cin >> name >> beforeDec >> dec >> afterDec;
        parties[name] = beforeDec * 10 + afterDec;
    }
    cin.clear();
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        double left = 0;
        int right = 0;
        string line, comp;
        getline(cin, line);
        istringstream ss(line);
        int b = 0;
        while (ss >> line)
        {
            if (line == "=" || line == "<" || line == ">" || line == "<=" || line == ">=")
            {
                comp = line;
                b = 1;
            }
            else if (line != "+")
            {
                if (!b)
                    left += parties[line];
                else
                    right = stoi(line) * 10;
            }
        }
        printf("Guess #%d was ", i + 1);
        if (comp == "=")
        {
            if (left == right)
                cout << "correct.\n";
            else
                cout << "incorrect.\n";
        }
        if (comp == "<")
        {
            if (left < right)
                cout << "correct.\n";
            else
                cout << "incorrect.\n";
        }
        if (comp == ">")
        {
            if (left > right)
                cout << "correct.\n";
            else
                cout << "incorrect.\n";
        }
        if (comp == "<=")
        {
            if (left <= right)
                cout << "correct.\n";
            else
                cout << "incorrect.\n";
        }
        if (comp == ">=")
        {
            if (left >= right)
                cout << "correct.\n";
            else
                cout << "incorrect.\n";
        }
    }
    return 0;
}