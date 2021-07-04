// 1. You are given a partially written LinkedList class.
// 2. Here is a list of existing functions:
//    2.1 addLast - adds a new element with given value to the end of Linked List
//    2.2. display - Prints the elements of linked list from front to end in a single line. All
//      elements are separated by space
//      2.3. size - Returns the number of elements in the linked list.
// 3. You are required to complete the body of removeFirst function
//      3.1. removeFirst - This function is required to remove the first element from
//           Linked List. Also, if there is only one element, this should set head and tail to
//           null. If there are no elements, this should print "List is empty".
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
    }
    return 0;
}
