#include <iostream>
using namespace std;

// structure of node
struct Node
{
    //    * data *
    int data;
    struct Node *next;
} *top = NULL; // declare as global so that no need to extra passing node to any function

void push(int x)
{
    struct Node *temp;
    temp = new Node;
    if (temp == NULL)
    {
        cout << "stack is full\n";
    }
    else
    {
        temp->data = x;
        temp->next = top;
        top = temp;
    }
}

int pop()
{
    struct Node *p;
    int x;
    if (top == NULL)
    {
        cout << "stack is empty\n";
    }
    else
    {
        p = top;
        top = top->next;
        x = p->data;
        free(p);
    }
    return x;
}

void display()
{
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    display();
    cout << pop();
}
