// this is stack implementation using array i.e static implementation

#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// create stack structure
struct stack_create
{
    /* data */
    int size;
    int top;
    int *S; // array to store value dynamically allocated
};
// memory and value allocation
void create_stack(struct stack_create *st)
{
    // struct stack_create st;
    cout << "Enter size of stack: " << endl;
    cin >> st->size;
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
    // int *S = new int[st->size];
}
// to display stack
void display(struct stack_create st)
{
    int i;
    for (i = st.top; i >= 0; i--)
    {
        cout << st.S[i];
    }
    cout << endl;
}
// push element to the stack
void Push(struct stack_create *st, int x)
{
    if (st->top == st->size - 1)
    {
        cout << "stack overflow" << endl;
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}
// pop element from the stack
int pop(struct stack_create *st)
{
    int x = -1;
    if (st->top == -1)
    {
        cout << "stack underflow\n";
    }
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}
int isempty(struct stack_create st)
{
    if (st.top == -1)
    {
        return 1;
    }
    return 0;
}
int isfull(struct stack_create st)
{
    if (st.top == st.size - 1)
    {
        return 1;
    }
    return 0;
}
int stacktop(struct stack_create st)
{
    if (!isempty(st))
        return st.S[st.top];
    return -1;
}
int peek(struct stack_create *st, int loc)
{
    int x = -1;
    if (st->top - loc + 1 < 0)
    {
        cout << "invalid index\n";
    }
    else
    {
        x = st->S[st->top - loc + 1];
    }
    return x;
}
int main()
{
    struct stack_create st;
    create_stack(&st);
    Push(&st, 1);
    Push(&st, 2);
    Push(&st, 3);
    Push(&st, 4);

    cout << pop(&st) << endl;
    cout << pop(&st) << endl;
    display(st);
    cout << isempty(st);
    cout << isfull(st);
    cout << stacktop(st);
    cout << peek(&st, 1);
}