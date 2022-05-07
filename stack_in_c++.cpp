#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top == NULL;
    }
    void push(int x);
    int pop();
    void display();
};
void Stack::push(int x)
{
    Node *t;
    t = new Node;
    if (t == NULL)
    {
        cout << "stack is full\n";
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop()
{
    Node *t;
    int x = -1;
    if (top == NULL)
    {
        cout << "stack is empty\n";
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Stack::display()
{
    Node *p = top;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(40);
    stk.push(40);
    stk.push(40);
    stk.push(40);
    stk.display();
    // cout << stk.pop() << endl;
    // cout << stk.pop();
}