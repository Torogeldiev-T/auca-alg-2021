#pragma once
#include <cstddef>
#include <initializer_list>
template <typename T>
class List
{
    struct Node
    {
        T mData;
        Node *mPrev;
        Node *mNext;
        Node(const T &data, Node *prev, Node *next) : mData(data), mPrev(prev), mNext(next)
        {
        }
    };
    Node *mHead;
    std::size_t msize;

public:
    List() : mHead(new Node(T(), nullptr, nullptr)), msize(0)
    {
        // mHead = nullptr;
        mHead->mNext = mHead;
        mHead->mPrev = mHead;
    }
    List(const List &other) : mHead(new Node(T(), nullptr, nullptr)), msize(0)
    {
        mHead->mNext = mHead;
        mHead->mPrev = mHead;
        for (auto i = other.begin(); i != other.end(); i++)
        {
            pushBack(*i);
        }
    }
    // List(List &&other) : mHead(new Node(T(), nullptr, nullptr)), mTail(new Node(T(), nullptr, nullptr)), msize(0)
    // {
    //     mHead = other.mTail;
    //     mTail = other.mHead;
    //     other.mHead = nullptr;
    //     other.mTail = nullptr;
    // }
    // List &operator=(const List &other)
    // {
    //     if (this != &other) // not a self-assignment
    //     {
    //         if (msize != other.msize) // resource cannot be reused
    //         {
    //             mHead = other.mTail;
    //             mTail = other.mHead;
    //             size = other.size;
    //         }
    //         std::copy(&other.begin(), &other.end(), &mHead);
    //     }
    //     return *this;
    // }
    std::string toStr() const
    {
        std::ostringstream out;
        out << "{";
        Node *p = mHead->mNext;
        for (std::size_t i = 0; i < msize; ++i)
        {
            if (i != 0)
            {
                out << ", ";
            }
            out << p->mData;
            p = p->mNext;
        }
        out << "}";
        return out.str();
    }

    std::string toReversedStr() const
    {
        std::ostringstream out;
        out << "{";
        Node *p = mHead->mPrev;
        for (std::size_t i = 0; i < msize; ++i)
        {
            if (i != 0)
            {
                out << ", ";
            }
            out << p->mData;
            p = p->mPrev;
        }
        out << "}";
        return out.str();
    }
    void clear()
    {
        while (begin() != end())
        {
            erase(begin());
        }
        erase(begin());
    }

    std::size_t size() const
    {
        return msize;
    }

    void pushBack(const T &x)
    {
        Node *t = new Node(x, mHead->mPrev, mHead);
        mHead->mPrev->mNext = t;
        mHead->mPrev = t;
        msize++;
    }
    void popBack()
    {
        if (msize == 0)
            return;
        Iter r = end();
        --r;
        r.mPtr->mPrev->mNext = mHead;
        r.mPtr->mNext->mPrev = r.mPtr->mPrev;
        delete r.mPtr;
        msize--;
    }
    void pushFront(const T &x)
    {
        Node *t = new Node(x, mHead, mHead->mNext);
        mHead->mNext->mPrev = t;
        mHead->mNext = t;
        msize++;
    }
    void popFront()
    {
        if (msize == 0)
            return;
        Iter r = begin();
        r.mPtr->mNext->mPrev = mHead;
        r.mPtr->mPrev->mNext = r.mPtr->mNext;
        delete r.mPtr;
        msize--;
    }

    class Iter;
    class RIter;

    Iter erase(Iter pos)
    {
        Iter r = pos;
        ++r;

        pos.mPtr->mPrev->mNext = pos.mPtr->mNext;
        pos.mPtr->mNext->mPrev = pos.mPtr->mPrev;
        delete pos.mPtr;
        --msize;
        return r;
    }

    Iter begin() const
    {
        Iter r;
        r.mPtr = mHead->mNext;
        return r;
    }

    Iter end() const
    {
        Iter r;
        r.mPtr = mHead;
        return r;
    }

    RIter rbegin() const
    {
        RIter r;
        r.mPtr = mHead->mPrev;
        return r;
    }

    RIter rend() const
    {
        RIter r;
        r.mPtr = mHead;
        return r;
    }
};

template <typename T>
class List<T>::Iter
{
    friend class List<T>;
    Node *mPtr;

public:
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;

    Iter() : mPtr(nullptr)
    {
    }

    T &operator*() const
    {
        return mPtr->mData;
    }
    T *operator->() const
    {
        return &(mPtr->mData);
    }
    //++p
    Iter &
    operator++()
    {
        mPtr = mPtr->mNext;
        return *this;
    }

    //p++
    Iter operator++(int)
    {
        Iter r = *this;
        mPtr = mPtr->mNext;
        return r;
    }

    Iter &operator--()
    {
        mPtr = mPtr->mPrev;
        return *this;
    }

    Iter operator--(int)
    {
        Iter *r = *this;
        mPtr = mPtr->mPrev;
        return r;
    }

    bool operator==(const Iter &other) const
    {
        return mPtr == other.mPtr;
    }

    bool operator!=(const Iter &other) const
    {
        return !(*this == other);
    }
};
template <typename T>
class List<T>::RIter
{
    friend class List<T>;
    Node *mPtr;

public:
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;

    RIter() : mPtr(nullptr)
    {
    }

    T &operator*() const
    {
        return mPtr->mData;
    }

    //++p
    RIter &operator++()
    {
        mPtr = mPtr->mPrev;
        return *this;
    }

    //p++
    RIter operator++(int)
    {
        Iter r = *this;
        mPtr = mPtr->mPrev;
        return r;
    }

    RIter &operator--()
    {
        mPtr = mPtr->mNext;
        return *this;
    }

    RIter operator--(int)
    {
        Iter *r = *this;
        mPtr = mPtr->mNext;
        return r;
    }

    bool operator==(const RIter &other) const
    {
        return mPtr == other.mPtr;
    }

    bool operator!=(const RIter &other) const
    {
        return !(*this == other);
    }
};