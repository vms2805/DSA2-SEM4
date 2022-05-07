#include <iostream>
//#include<bits/stdc++.h>
#include <stdlib.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class stack
{
private:
    /* data */
    Node *top;

public:
    stack()
    {
        top = NULL;
    }
    void push(/* args */ int x);
    int pop();
    // int check_expression(string exp);
    int stacktop();
    int isoperand(char x);
    int precedence(char x);
    int evaluate(char *postfix);
};
void stack::push(int x)
{
    Node *temp;
    temp = new Node;
    if (temp == NULL)
    {
        cout << "full\n";
    }
    else
    {
        temp->data = x;
        temp->next = top;
        top = temp;
    }
}

int stack::pop()
{
    int x;
    Node *p;
    if (top == NULL)
    {
        cout << "empty\n";
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
/*int stack::check_expression(string exp)
{
    int i;
    char x;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
        {
            if (top == NULL)
            {
                return 0;
            }
            else
            {
                x = stacktop();
                if ((x == '(' && exp[i] == ')') || (x == '{' && exp[i] == '}') || (x == '[' && exp[i] == ']'))
                {
                    pop();
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}*/
int stack::isoperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int stack::precedence(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

int stack::stacktop()
{
    if (top == NULL)
    {
        return -1;
    }
    else
    {
        return top->data;
    }
}
// evaluation of postfix expression
int stack::evaluate(char *postfix)
{
    int i, x1, x2, r;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isoperand(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            x2 = pop();
            x1 = pop();
            switch (postfix[i])
            {
            case '+':
                /* code */
                r = x1 + x2;
                push(r);
                break;
            case '*':
                /* code */
                r = x1 * x2;
                push(r);
                break;
            case '/':
                /* code */
                r = x1 / x2;
                push(r);
                break;
            case '-':
                /* code */
                r = x1 - x2;
                push(r);
                break;
            default:
                break;
            }
        }
    }
    return pop();
}
int main()
{
    stack s;

    char *postfix = "35*62/+4-";
    cout << s.evaluate(postfix);
}
