#include <iostream>
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
    int check_expression(string exp);
    int stacktop();
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
int stack::check_expression(string exp)
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
int main()
{
    stack s;
    string exp = "[{{[()]}}";
    cout << s.check_expression(exp);
}
