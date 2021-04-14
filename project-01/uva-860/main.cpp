#include <iostream>
#include <unordered_map>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    unordered_map<string, int> m;
    int counter = 0;
    while (getline(cin, s) && s != "****END_OF_INPUT****")
    {
        if (s == "****END_OF_TEXT****")
        {
            double sum = 0, max = log10f(counter);
            for (auto i = m.begin(); i != m.end(); i++)
            {
                sum += (log10f(counter) - log10f(i->second)) * i->second;
            }
            sum = (1.0f / counter) * sum;
            double rel = sum * 100 / max;
            printf("%d %.1f %.0f\n", counter, sum, rel);
            counter = 0;
            m.clear();
        }
        else
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == ',' || s[i] == '.' || s[i] == ':' || s[i] == ';' || s[i] == '!' || s[i] == '?' || s[i] == '"' || s[i] == '(' || s[i] == ')' || s[i] == '\t' || s[i] == '\n')
                    s[i] = ' ';
                s[i] = tolower(s[i]);
            }
            stringstream ss(s);
            while (ss >> s)
            {
                auto p = m.insert({s, 1});
                if (!p.second)
                {
                    p.first->second++;
                }
                counter++;
            }
        }
    }
}
