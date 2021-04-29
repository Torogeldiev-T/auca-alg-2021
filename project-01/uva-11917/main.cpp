#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int T;
    cin >> T;
    for (int l = 0; l < T; l++)
    {
        int n;
        cin >> n;
        unordered_map<string, int> m;
        for (int i = 0; i < n; i++)
        {
            string subject;
            int days;
            cin >> subject >> days;
            m[subject] = days;
        }
        string sjct_to_submit;
        int deadline;
        cin >> deadline >> sjct_to_submit;
        printf("Case %d: ", l + 1);
        if (m.find(sjct_to_submit) != m.end() && m[sjct_to_submit] <= deadline)
        {
            cout << "Yesss\n";
        }
        else if (m.find(sjct_to_submit) != m.end() && m[sjct_to_submit] <= deadline + 5)
        {
            cout << "Late\n";
        }
        else
        {
            cout << "Do your own homework!\n";
        }
    }
}