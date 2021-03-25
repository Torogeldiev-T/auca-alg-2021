#include <iostream>
using namespace std;
struct Node
{
    int mData;
    Node *mPrev;
    Node *mNext;
    Node(int data, Node *prev, Node *next) : mData(data), mPrev(prev), mNext(next)
    {
    }
};
void printInDirectOrder(Node *head)
{
    for (Node *p = head; p; p = p->mNext)
    {
        cout << " " << p->mData;
    }
    cout << endl;
}
void printInReverseOrder(Node *tail)
{
    for (Node *p = tail; p; p = p->mPrev)
    {
        cout << " " << p->mData;
    }
    cout << endl;
}
void pushBack(Node *&head, Node *&tail, int data)
{
    if (head == nullptr)
    {
        head = tail = new Node(data, nullptr, nullptr);
    }
    else
    {
        tail->mNext = new Node(data, tail, nullptr);
        tail = tail->mNext;
    }
}
void clear(Node *&head, Node *&tail)
{
    for (Node *&p = head; p;)
    {
        Node *t = p->mNext;
        delete[] p;
        p = t;
    }
    head = tail = nullptr;
}
void insertBefore(Node *&head, Node *curr, int data)
{
    if (curr == head)
    {
        curr->mPrev = new Node(data, nullptr, curr);
        head = curr->mPrev;
    }
    else
    {
        Node *t = new Node(data, curr->mPrev, curr);
        t->mPrev->mNext = t;
        t->mNext->mPrev = t;
    }
}
Node *erase(Node *&head, Node *&tail, Node *curr)
{

    if (head == curr && tail == curr)
    {
        delete head;
        head = tail = nullptr;
        return nullptr;
    }
    else if (head == curr)
    {
        head = head->mNext;
        head->mPrev = nullptr;
        delete curr;
        return head;
    }
    else if (tail == curr)
    {
        tail = tail->mPrev;
        tail->mNext = nullptr;
        delete curr;
        return nullptr;
    }
    else
    {
        Node *t = curr->mNext;
        curr->mPrev->mNext = curr->mNext;
        curr->mNext->mPrev = curr->mPrev;
        delete curr;
        return t;
    }
}
int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    for (int x; cin >> x;)
        pushBack(head, tail, x);

    printInDirectOrder(head);
    printInReverseOrder(tail);

    for (Node *p = head; p; p = p->mNext)
    {
        if (p->mData % 2 == 0)
        {
            insertBefore(head, p, 0);
        }
    }
    printInDirectOrder(head);
    printInReverseOrder(tail);

    for (Node *p = head; p;)
    {
        if (p->mData % 2 == 0)
        {
            p = erase(head, tail, p);
        }
        else
        {
            p = p->mNext;
        }
    }
    printInDirectOrder(head);
    printInReverseOrder(tail);
}