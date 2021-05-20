#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;
    string temp;
    getline(cin, temp);
    n = stoi(temp);
    getline(cin, temp);
    while (n--)
    {
        map<string, int> logbook;
        int total = 0;
        string s;
        while (getline(cin, s) && s != "")
        {
            if (logbook.count(s) == 0)
            {
                logbook[s] = 1;
            }
            else
                logbook[s] = logbook[s] + 1;

            total++;
        }

        for (auto it = logbook.begin(); it != logbook.end(); it++)
        {
            cout << it->first << " ";
            printf("%.4lf\n", (double)it->second / (double)total * 100.0);
        }
        if (n > 0)
        {
            printf("\n");
        }
    }

    return 0;
}