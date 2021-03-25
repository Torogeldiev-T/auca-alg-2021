#pragma once
#include <vector>
#include <string>
#include <iostream>
class HashSetStr
{
public:
    HashSetStr()
        : buckets(11, nullptr), sz(0)
    {
    }
    std::size_t size() const
    {
        return sz;
    }
    ~HashSetStr()
    {
        clear();
    }
    bool erase(const std::string &s);
    bool insert(const std::string &s);
    void clear();
    bool find(const std::string &s);
    void print() const;

private:
    struct Node
    {
        std::string mData;
        Node *mNext;
        Node(const std::string &data, Node *next)
            : mData(data), mNext(next)
        {
        }
    };
    void rehash();
    std::vector<Node *> buckets;
    std::size_t sz;
};