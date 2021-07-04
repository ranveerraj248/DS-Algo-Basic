// 1. You are required to complete the code of our LLToQueueAdapter class.
// 2. As data members, you've a linkedlist available in the class.
// 3. Here is the list of functions that you are supposed to complete
//      3.1. add -> Should accept new data in FIFO manner
//      3.2. remove -> Should remove and return data in FIFO manner. If not available,
//      print "Queue underflow" and return -1.
//      3.3. peek -> Should return data in FIFO manner. If not available, print "Queue
//      underflow" and return -1.
//      3.4. size -> Should return the number of elements available in the queue
#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
class Queue
{
    Node *rear, *front;

public:
    Queue()
    {
        front = rear = NULL;
    }
    void add(int val)
    {
        Node *temp = new Node(val);
        if (rear == NULL)
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    int remove()
    {
        if (front == NULL)
        {
            cout << "Queue underflow" << endl;
            return -1;
        }
        Node *temp = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        int data = temp->data;
        free(temp);
        return data;
    }
    int peek()
    {
        if (front == NULL)
        {
            cout << "Queue underflow" << endl;
            return -1;
        }
        Node *temp = front;
        int data = temp->data;
        free(temp);
        return data;
    }
    int size()
    {
        int count = 0;
        Node *current = front;
        while (current != NULL)
        {
            count++;
            current = current->next;
        }
        return count;
    }
};
int main()
{
    string str = "";
    Queue q;
    while ("quit" != str)
    {
        getline(cin, str);
        if ("add" == str.substr(0, 3))
        {
            int val = stoi(str.substr(4));
            q.add(val);
        }
        else if ("remove" == str)
        {
            int val = q.remove();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if ("peek" == str)
        {
            int val = q.peek();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if ("size" == str)
        {
            cout << q.size() << endl;
        }
    }
}