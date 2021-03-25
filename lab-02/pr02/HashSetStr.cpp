#include "HashSetStr.hpp"
using namespace std;
size_t defaultHashFunc(const string &s)
{
    size_t r = 0;
    for (auto c : s)
    {
        r += 31 * c + 97;
    }
    return r;
}
bool HashSetStr::insert(const string &k)
{
    size_t index = defaultHashFunc(k) % buckets.size();
    for (auto p = buckets[index]; p != nullptr; p = p->mNext)
    {
        if (p->mData == k)
        {
            return false;
        }
    }
    if (sz == buckets.size())
    {
        rehash();
        index = defaultHashFunc(k) % buckets.size();
    }
    buckets[index] = new Node(k, buckets[index]);
    ++sz;
    return true;
}
void HashSetStr::rehash()
{
    vector<Node *> newBuckets(2 * buckets.size() + 1, nullptr);
    for (size_t i = 0; i < buckets.size(); i++)
    {
        while (buckets[i] != nullptr)
        {
            size_t index = defaultHashFunc(buckets[i]->mData) % newBuckets.size();
            Node *t = buckets[i];
            buckets[i] = buckets[i]->mNext;
            t->mNext = newBuckets[index];
            newBuckets[index] = t;
        }
        buckets.swap(newBuckets);
    }
}
void HashSetStr::clear()
{
    for (size_t i = 0; i < buckets.size(); ++i)
    {
        while (buckets[i] != nullptr)
        {
            Node *t = buckets[i];
            buckets[i] = buckets[i]->mNext;
            delete t;
        }
    }
    sz = 0;
}
bool HashSetStr::erase(const string &s)
{
    size_t index = defaultHashFunc(s) % buckets.size();
    for (Node *prev = nullptr, *i = buckets[index]; i != nullptr;)
    {
        if (i->mData == s)
        {
            if (prev != nullptr)
            {
                prev->mNext = i->mNext;
            }
            else
            {
                buckets[index] = i->mNext;
            }
            Node *t = i;
            i = i->mNext;
            delete t;

            sz--;
            return true;
        }
        else
        {
            i = i->mNext;
        }
        prev = i;
    }
    return false;
}
bool HashSetStr::find(const string &s)
{
    for (size_t i = 0; i < buckets.size(); ++i)
    {
        while (buckets[i] != nullptr)
        {
            Node *t = buckets[i];
            if (t->mData == s)
            {
                return true;
            }
            buckets[i] = buckets[i]->mNext;
        }
    }
    return false;
}
void HashSetStr::print() const
{
    for (size_t i = 0; i < buckets.size(); ++i)
    {
        cout << i << ":";
        for (Node *cur = buckets[i]; cur != nullptr; cur = cur->mNext)
        {
            cout << " " << cur->mData;
        }
        cout << "\n";
    }
}