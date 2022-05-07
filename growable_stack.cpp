// Growable array is the array with no limit means we can add array size as stack going
// to full using two stratergies
// 1. Tight stratergy: add constant amount to array(n+c)
// 2. Growth startergy: Double the size of old stack.

// Implememtation of Growable stack array using Tight stratergy

#include <iostream>
using namespace std;
// define specific number to increase size of the array
#define Bound 4
int top = -1;
int lenght = 0;
int *create_new(int *a)
{
    // allocate memory for new stack
    int *new_a = new int[lenght + Bound];
    // copying all element to new stack
    for (int i = 0; i <= top; i++)
    {
        new_a[i] = a[i];
    }
    // resize the length
    lenght = lenght + Bound;
    return new_a;
}
// push function
int *push(int *a, int x)
{
    // if stack is full increase the memory of the stack
    if (top == lenght - 1)
    {
        a = create_new(a);
    }
    a[++top] = x;
    return a;
}
void pop(int *a)
{
    top--;
}
void display(int *a)
{
    if (top == -1)
        cout << "stack is empty\n";
    else
        cout << "stack: ";
    for (int i = 0; i <= top; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int *a = create_new(a);
    a = push(a, 1);
    a = push(a, 2);
    a = push(a, 3);
    a = push(a, 4);
    a = push(a, 15);
    display(a);
    a = push(a, 16);
    a = push(a, 6);
    a = push(a, 7);
    display(a);
    a = push(a, 8);
    a = push(a, 9);
    display(a);
}