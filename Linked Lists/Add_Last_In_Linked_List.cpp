// 1. You are given a partially written LinkedList class.
// 2. You are required to complete the body of addLast function. This function is supposed to add an element to the end of LinkedList. You are required to update head, tail and size as required.
// 3. Input and Output is managed for you. Just update the code in addLast function.
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
    }
    testList(list);
    return 0;
}