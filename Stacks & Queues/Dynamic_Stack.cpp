// 1. You are given the code of our CustomStack class which mimics the java.util.Stack class.
// 2. Here is the list of functions that are written in the class
//     2.1. push -> Accepts new data if there is space available in the underlying array or
//      print "Stack overflow" otherwise
//      2.2. pop -> Removes and returns last data if available or print "Stack underflow"
//      otherwise and returns -1
//      2.3. top -> Return last data if available or print "Stack underflow" otherwise and
//       returns -1
//      2.4. size -> Returns the number of elements available in the stack
//      2.5. display -> Print the elements of stack in LIFO manner (space-separated)
//      ending with a line-break.
// 3. Input and Output are managed for you.
// 4. You are required to change the body of push function to accept the element even when the data array is completely full. In that case, you are required to reallocate the data array (to twice it's size). You should not print "Stack overflow" ever.
#include <iostream>
#include <cstring>
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
            int newsize = 2 * capacity;
            int *newArray = new int[newsize];
            memcpy(newArray, data, capacity * sizeof(int));
            capacity = newsize;
            delete[] data;
            data = newArray;
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