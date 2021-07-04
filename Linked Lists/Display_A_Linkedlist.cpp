// 1. You are given a partially written LinkedList class.
// 2. Here is a list of existing functions:
//    2.1 addLast - adds a new element with given value to the end of Linked List
// 3. You are required to complete the body of display function and size function
//    3.1. display - Should print the elements of linked list from front to end in a single line. Elements should be separated by space.
//    3.2. size - Should return the number of elements in the linked list.

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
    int Size()
    {
        int x = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            x++;
            temp = temp->next;
        }
        return x;
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
};
void testList(LinkedList list)
{
    for (Node *temp = list.head; temp != NULL; temp = temp->next)
    {
        cout << temp->data << endl;
    }
    cout << list.size << endl;
    if (list.size > 0)
    {
        cout << list.tail->data << endl;
    }
}
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
    }
    //testList(list);
    return 0;
}