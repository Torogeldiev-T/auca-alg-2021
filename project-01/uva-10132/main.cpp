#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    cin.ignore();
    cin.clear();
    getline(cin, s);
    for (int k = 0; k < n; k++)
    {
        vector<string> v;
        unordered_map<string, int> m;
        int c = 0;
        while (getline(cin, s) && s != "")
        {
            v.push_back(s);
        }

        //put all possible variants, increasing its value, if its repieted
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                ++m[v[i] + v[j]];
                ++m[v[j] + v[i]];
            }
        }
        //get the most occured string
        unordered_map<string, int>::iterator file = m.begin();
        for (auto iter = m.begin(); iter != m.end(); ++iter)
        {
            if (iter->second > file->second)
                file = iter;
        }
        cout << file->first << endl;
        if (k != n - 1)
            cout << endl;
    }
}
