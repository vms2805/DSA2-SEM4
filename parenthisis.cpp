#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct stack
{
    int size;
    int top;
    char *S;
};
void create_stack(struct stack *st)
{
    st->size = 20;
    st->top = -1;
    st->S = (char *)malloc(st->size * sizeof(char));
}
void push(struct stack *st, char x)
{
    if (st->top == st->size - 1)
    {
        cout << "stack is full\n";
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}
char pop(struct stack *st)
{
    char x;
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
int check_balancing(struct stack *st, string exp)
{
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(st, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (st->top == -1)
            {
                return 0;
            }
            pop(st);
        }
    }
    if (st->top == -1)
    {
        return 1;
    }
    else
        return 0;
}
int main()
{
    string exp = "(((a*b)()-(c*f)))";
    struct stack st;
    create_stack(&st);
    cout << check_balancing(&st, exp);
    return 0;
}