//링크드 리스트의 시작은 O(1) 끝에서 넣으면 O(n)
// 추가로 push하면 맨 위에 node를 추가할 수 있다.
// all function has constant time O

#include <stdio.h>

struct Node
{
    int data;
    Node* next;
}* top = NULL;

void push(int x)
{
    Node* t;
    t = new Node;

    if(t == NULL)
        printf("Stack is FUll\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
    
}

int pop()
{
    int x = -1;
    Node* t = NULL;
    if(top == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void Display()
{
    Node* p;
    p = top;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    Display();
    printf("%d ", pop());
    
}