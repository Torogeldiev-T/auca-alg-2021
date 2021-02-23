#include <iostream>
#include <set>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int k = 0; k < n; k++)
    {
        int b, sg, sb;
        multiset<int> sgs;
        multiset<int> sbs;
        cin >> b >> sg >> sb;
        for (int i = 0; i < sg; i++)
        {
            int power;
            cin >> power;
            sgs.insert(power);
        }
        for (int i = 0; i < sb; i++)
        {
            int power;
            cin >> power;
            sbs.insert(power);
        }
        while (true)
        {
            multiset<int>::iterator p, p2;
            vector<int> sgs_survived;
            vector<int> sbs_survived;
            int sz = min(sgs.size(), sbs.size());
            for (int i = 0; i < b; i++)
            {
                p = --sgs.end();
                p2 = --sbs.end();
                if (*p > *p2)
                {
                    sgs_survived.push_back(*p - *p2);
                }
                else if (*p < *p2)
                {
                    sbs_survived.push_back(*p2 - *p);
                }
                sbs.erase(p2);
                sgs.erase(p);
                if (i + 1 == sz)
                    break;
            }
            if (sgs_survived.size() != 0)
            {
                for (int i = 0; i < sgs_survived.size(); i++)
                {

                    sgs.insert(sgs_survived[i]);
                }
                sgs_survived.clear();
            }
            if (sbs_survived.size() != 0)
            {
                for (int i = 0; i < sbs_survived.size(); i++)
                {

                    sbs.insert(sbs_survived[i]);
                }
                sbs_survived.clear();
            }
            if (sgs.empty() || sbs.empty())
            {
                break;
            }
        }
        if (sgs.empty() && sbs.empty())
            cout << "green and blue died\n";
        else if (sgs.empty())
        {
            cout << "blue wins\n";
            for (multiset<int>::iterator end = --sbs.end(); end != sbs.begin(); end--)
            {
                cout << *end << endl;
            }
            cout << *sbs.begin() << endl;
        }
        else if (sbs.empty())
        {
            cout << "green wins\n";
            for (multiset<int>::iterator end = --sgs.end(); end != sgs.begin(); end--)
            {
                cout << *end << endl;
            }
            cout << *sgs.begin() << endl;
        }
        if (k != n - 1)
            cout << endl;
    }
}