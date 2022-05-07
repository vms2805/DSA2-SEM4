#include <iostream>
//#include<bits/stdc++.h>
#include <stdlib.h>
using namespace std;
class Node
{
public:
    char data;
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
    void push(/* args */ char x);
    char pop();
    // int check_expression(string exp);
    int stacktop();
    int isoperand(char x);
    int precedence(char x);
    char *convert(char *infix, int len);
};
void stack::push(char x)
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

char stack::pop()
{
    char x;
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
char *stack::convert(char *infix, int len)
{
    char *postfix;
    postfix = (char *)malloc((len + 2) * sizeof(char));
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (isoperand(infix[i]))
        {
            // postfix[j++] = infix[i++];
            push(infix[i++]);
        }
        else
        {
            if (top == nullptr)
            {
                push(infix[i++]);
            }
            else if (precedence(infix[i]) > precedence(top->data))
            {
                push(infix[i++]);
            }
            else
            {
                postfix[j++] = pop();
            }
        }
    }
    while (top != nullptr)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
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
int main()
{
    stack s;

    char *infix = "a+b*c-d/e";
    int len;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        len++;
    }
    char *postfix = s.convert(infix, len);
    cout << postfix;
}
