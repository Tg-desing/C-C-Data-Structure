#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

class LinkedList
{
private:
    Node* first;

public:
    LinkedList()
    {
        Node* first = NULL;
    };

    LinkedList(int A[], int n);
    ~LinkedList();

    int Count();
    void Display();
    Node* Search(int key);
    void Insert(int x, int index);
    int Delete(int index);
    void Reverse();
    int isLoop();
};

LinkedList::LinkedList(int A[], int n)
{
    Node* t;
    Node* last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t; 
    }
}

LinkedList::~LinkedList()
{
    Node* p = first;
    Node* t = NULL;

    while(p)
    {
        if(p)
        {
            t = p;
            p = p->next;
            delete t;
        }
    }
}

int LinkedList::Count()
{
    Node* p = first;
    int count = 0;

    while(p)
    {
        if (p)
            count++;

        p = p->next;
    }

    return count;
}

void LinkedList::Display()
{
    Node* t = first;

    while(t)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int LinkedList::Delete(int index)
{
    Node* p;
    Node* q;
    int x;

    if (index < 1 || index > Count())
        return -1;
    
    if (index == 1)
    {
        p = first;
        x = p->data;
        first = p->next;
        delete p;
        return x;
    }
    else
    {
        p = first;

        for (int i = 0; i < index - 1 && p; i++)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        x = p->data;
        delete p;
        return x;

        
    }
}

void LinkedList::Insert(int index, int x)
{
    Node* t = new Node;
    t->data = x;
    t->next = NULL;

    Node* p = first;
    Node* q;

    if (!p)
    {
        first = t;
    }
    else
    {
        if (index == 0)
        {
            t->next = first;
            first = t;
        }

        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;        
        }
        t->next = p->next;
        p->next = t;
    }
}

void LinkedList::Reverse()
{
    Node* p = first, *q = NULL, *r = NULL;

    while(p)
    {
        r = q;
        q = p;
        p = p->next;

        r = q->next;
    }
    first = q;
}

Node* LinkedList::Search(int key)
{
    Node* q = NULL, *p = first;

    while(p)
    {
        if (p->data == key)
            return p;

        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

int LinkedList::isLoop()
{
    Node* p = first, *q = first;


    do {
        p = p->next;
        q = q->next;

        q = q ? q->next : q;
    } while(p && q && p != q);

    if (p == q)
        return 1;
    else
        return 0;
}

int main()
{
    int A[]={1,6,8,12,56};
    LinkedList l(A,5);
   
    l.Insert(2,67);

     l.Display();

    cout<<"lenght "<<l.Count()<<endl;


    l.Delete(1);
    cout<<"After deletion"<<endl;
    l.Display();
    return  0;
}