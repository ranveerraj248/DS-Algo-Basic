// 1. You are given a partially written LinkedList class.
// 2. Here is a list of existing functions:
//     2.1 addLast - adds a new element with given value to the end of Linked List
//     2.2. display - Prints the elements of linked list from front to end in a single line.
//      All elements are separated by space.
// 2.3. size - Returns the number of elements in the linked list.
// 2.4. removeFirst - Removes the first element from Linked List.
// 3. You are required to complete the body of getFirst, getLast and getAt function
// 3.1. getFirst - Should return the data of first element. If empty should return -1 and print "List is empty".
// 3.2. getLast - Should return the data of last element. If empty should return -1 and print "List is empty".
// 3.3. getAt - Should return the data of element available at the index passed. If empty should return -1 and print "List is empty". If invalid index is passed, should return -1 and print "Invalid arguments".
#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class LinkedList
{
public:
    Node *head;
    Node *tail;
    int size;
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void addLast(int val)
    {

        Node *tmp = new Node();
        tmp->data = val;
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
        size++;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int Size()
    {
        return size;
    }
    void removeFirst()
    {
        if (size == 0)
        {
            cout << "List is empty";
        }
        else if (size == 1)
        {
            head = NULL;
            tail = NULL;
            size = 0;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            size--;
        }
    }
    int getFirst()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return -1;
        }
        else
        {
            return head->data;
        }
    }
    int getLast()
    {
        if (tail == NULL)
        {
            cout << "List is empty" << endl;
            return -1;
        }
        else
        {
            return tail->data;
        }
    }
    int getAt(int index)
    {
        if (size == 0)
        {
            cout << "List is empty" << endl;
            return -1;
        }
        else if (index < 0 || index > size)
        {
            cout << "Invalid arguments" << endl;
            return -1;
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i <= index; i++)
            {
                temp = temp->next;
            }
            return temp->data;
        }
    }
};
int main()
{
    string str = "";
    LinkedList list;
    while (str != "quit")
    {
        getline(cin, str);
        if ("addLast" == str.substr(0, 7))
        {
            int val = stoi(str.substr(8));
            list.addLast(val);
        }
        else if ("display" == str)
        {
            list.display();
        }
        else if ("size" == str)
        {
            cout << list.Size() << endl;
        }
        else if ("removeFirst" == str)
        {
            list.removeFirst();
        }
        else if ("getFirst" == str)
        {
            int val = list.getFirst();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if ("getLast" == str)
        {
            int val = list.getLast();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if ("getAt" == str.substr(0, 5))
        {
            int val = stoi(str.substr(6));
            int data = list.getAt(val);
            if (data != -1)
            {
                cout << data << endl;
            }
        }
    }
    return 0;
}
