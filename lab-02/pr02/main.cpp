#include "HashSetStr.hpp"
#include <iostream>
#include <sstream>
using namespace std;
struct HashFunction
{
    size_t operator()(const string &s) const
    {
        //return 42;
        size_t r = 0;
        for (char c : s)
        {
            r = c * 97 + r * 31;
        }
        return r;
    }
};

int main()
{
    HashSetStr ht;
    //unordered_set<string> ht;
    //auto hash = HashFunction("dsadasdas");
    for (string line; getline(cin, line);)
    {
        istringstream sinp(line);
        string cmd;
        sinp >> cmd;
        if (cmd == "+")
        {
            string word;
            sinp >> word;
            // cout << "hash value: " << hash(word) << endl;
            // cout << "buket's index : " << hash(word) % ht.bucket_count() << endl;
            auto p = ht.insert(word);
            cout << (p ? "Yes" : "No") << endl;
        }
        else if (cmd == "?")
        {
            string word;
            sinp >> word;
            // cout << "hash value: " << hash(word) << endl;
            // cout << "buket's index : " << hash(word) % ht.bucket_count() << endl;
            bool it = ht.find(word);
            cout << (it ? "Yes" : "No") << endl;
        }
        else if (cmd == "-")
        {
            string word;
            sinp >> word;
            // cout << "hash value: " << hash(word) << endl;
            // cout << "buket's index : " << hash(word) % ht.bucket_count() << endl;
            cout << (ht.erase(word) == 1 ? "Yes" : "No") << endl;
        }
        else if (cmd == "#")
        {
            ht.print();
        }
    }
}