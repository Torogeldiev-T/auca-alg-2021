#include <unordered_map>
#include <iostream>
using namespace std;
int main()
{
    int count = 1;
    char s[6];
    unordered_map<string, int> m;
    for (s[0] = 'a'; s[0] <= 'z'; s[0]++)
    {
        s[1] = '\0';
        m[string(s)] = count++;
    }
    for (s[0] = 'a'; s[0] <= 'z' - 1; s[0]++)
        for (s[1] = s[0] + 1; s[1] <= 'z'; s[1]++)
        {
            s[2] = '\0';
            m[string(s)] = count++;
        }

    for (s[0] = 'a'; s[0] <= 'z' - 2; s[0]++)
        for (s[1] = s[0] + 1; s[1] <= 'z' - 1; s[1]++)
            for (s[2] = s[1] + 1; s[2] <= 'z'; s[2]++)
            {
                s[3] = '\0';
                m[string(s)] = count++;
            }

    for (s[0] = 'a'; s[0] <= 'z' - 3; s[0]++)
        for (s[1] = s[0] + 1; s[1] <= 'z' - 2; s[1]++)
            for (s[2] = s[1] + 1; s[2] <= 'z' - 1; s[2]++)
                for (s[3] = s[2] + 1; s[3] <= 'z'; s[3]++)
                {
                    s[4] = '\0';
                    m[string(s)] = count++;
                }

    for (s[0] = 'a'; s[0] <= 'z' - 4; s[0]++)
        for (s[1] = s[0] + 1; s[1] <= 'z' - 3; s[1]++)
            for (s[2] = s[1] + 1; s[2] <= 'z' - 2; s[2]++)
                for (s[3] = s[2] + 1; s[3] <= 'z' - 1; s[3]++)
                    for (s[4] = s[3] + 1; s[4] <= 'z'; s[4]++)
                    {
                        s[5] = '\0';
                        m[string(s)] = count++;
                    }
    string s1;
    while (cin >> s1)
    {
        auto iter = m.find(s1);
        if (iter == m.end())
            cout << 0 << "\n";
        else
            cout << iter->second << endl;
    }
}
