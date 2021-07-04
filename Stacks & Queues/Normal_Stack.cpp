// 1. You are required to complete the code of our CustomStack class. The class should mimic the behaviour of java.util.Stack class and implement LIFO semantic.
// 2. Here is the list of functions that you are supposed to complete
//    2.1. push -> Should accept new data if there is space available in the underlying
//    array or print "Stack overflow" otherwise.
//    2.2. pop -> Should remove and return last data if available or print "Stack
//    underflow" otherwise and return -1.
//    2.3. top -> Should return last data if available or print "Stack underflow"
//    otherwise and return -1.
//    2.4. size -> Should return the number of elements available in the stack.
//    2.5. display -> Should print the elements of stack in LIFO manner (space-
//    separated) ending with a line-break.
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class stack
{
    int *data;
    int tos;
    int capacity;

public:
    stack(int cap)
    {
        data = new int[cap];
        tos = -1;
        capacity = cap;
    }
    int size()
    {
        return tos + 1;
    }
    void display()
    {
        for (int i = tos; i >= 0; i--)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    void push(int val)
    {
        if (tos == capacity - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        data[++tos] = val;
    }
    int pop()
    {
        if (tos == -1)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return data[tos--];
    }
    int top()
    {
        if (tos == -1)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return data[tos];
    }
};
int main()
{
    int n;
    cin >> n;
    stack st(n);
    string str = "";
    while (str.compare("quit") != 0)
    {
        getline(cin, str);
        string temp = str;
        if ("push" == temp.substr(0, 4))
        {
            int val = stoi(temp.substr(4));
            st.push(val);
        }
        else if ("pop" == temp.substr(0, 3))
        {
            int val = st.pop();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if ("top" == temp.substr(0, 3))
        {
            int val = st.top();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if ("size" == temp.substr(0, 4))
        {
            cout << st.size() << endl;
        }
        else if ("display" == temp.substr(0, 7))
        {
            st.display();
        }
    }
    return 0;
}