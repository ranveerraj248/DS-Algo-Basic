// 1. You are required to complete the code of our LLToStackAdapter class.
// 2. As data members, you've a linkedlist available in the class.
// 3. Here is the list of functions that you are supposed to complete
//     3.1. push -> Should accept new data in LIFO manner
//     3.2. pop -> Should remove and return data in LIFO manner. If not
//      available, print "Stack underflow" and return -1.
//     3.3. top -> Should return data in LIFO manner. If not available, print
//     "Stack underflow" and return -1.
//     3.4. size -> Should return the number of elements available in the
//     stack
#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
Node *top;
int isEmpty()
{
    return top == NULL;
}
void push(int val)
{

    Node *temp = new Node();
    temp->data = val;
    temp->next = NULL;

    temp->next = top;
    top = temp;
}
int pop()
{
    Node *temp;
    if (top == NULL)
    {
        cout << "Stack underflow" << endl;
        return -1;
    }
    else
    {
        temp = top;

        top = top->next;

        temp->next = NULL;
        return temp->data;
        free(temp);
    }
}
int peek()
{
    if (!isEmpty())
    {
        return top->data;
    }
    else
    {
        cout << "Stack underflow" << endl;
        return -1;
    }
}
int size()
{
    int count = 0;
    Node *current = top;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
int main()
{
    string str = "";
    while ("quit" != str)
    {
        getline(cin, str);
        if ("push" == str.substr(0, 4))
        {
            int val = stoi(str.substr(5));
            push(val);
        }
        else if ("pop" == str)
        {
            int val = pop();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if ("top" == str)
        {
            int val = peek();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if ("size" == str)
        {
            cout << size() << endl;
        }
    }
}