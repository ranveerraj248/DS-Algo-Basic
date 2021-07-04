// 1. You are given a partially written LinkedList class.
// 2. Here is a list of existing functions:
//     2.1 addLast - adds a new element with given value to the end of Linked List
//     2.2. display - Prints the elements of linked list from front to end in a single line.
//     All elements are separated by space
//     2.3. size - Returns the number of elements in the linked list.
//     2.4. removeFirst - Removes the first element from Linked List.
//     2.5. getFirst - Returns the data of first element.
//     2.6. getLast - Returns the data of last element.
//     2.7. getAt - Returns the data of element available at the index passed.
//     2.8. addFirst - adds a new element with given value in front of linked list.
//     2.9. addAt - adds a new element at a given index.
//     2.10. removeLast - removes the last element of linked list.
//     2.11. removeAt - remove an element at a given index
// 3. You are required to complete the body of reversePI function.
//    The function should be an iterative function and should reverse the contents of linked list by changing the "next" property of nodes.
#include <iostream>
#include <string>
#include <sstream>
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
            cout << "List is empty" << endl;
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

    void addFirst(int val)
    {
        Node *temp = new Node();
        temp->data = val;
        temp->next = NULL;
        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        delete temp;
        size++;
    }
    void addAt(int index, int val)
    {
        if (index > size || index < 0)
        {
            cout << "Invalid arguments";
        }
        else if (index == 0)
        {
            addFirst(val);
        }
        else if (index == size)
        {
            addLast(val);
        }
        else
        {
            Node *prev = head;
            for (int i = 1; i <= index - 1; i++)
            {
                prev = prev->next;
            }
            Node *cur = prev->next;

            Node *newNode = new Node();
            newNode->data = val;
            newNode->next = NULL;

            prev->next = newNode;
            newNode->next = cur;
            size++;
        }
    }
    void removeLast()
    {
        if (size == 0)
        {
            cout << "List is empty" << endl;
        }
        else if (size == 1)
        {
            head = tail = NULL;
            size--;
        }
        else
        {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            tail = temp;
            tail->next = NULL;
            size--;
        }
    }
    void removeAt(int index)
    {

        if (size == 0)
        {
            cout << "List is empty" << endl;
        }
        else if (index < 0 || index >= size)
        {
            cout << "Invalid arguments" << endl;
        }
        else if (index == 0)
        {
            removeFirst();
        }
        else if (index == size - 1)
        {
            removeLast();
        }
        else
        {
            Node *prev = head;
            for (int i = 0; i < index - 1; i++)
            {
                prev = prev->next;
            }
            prev->next = prev->next->next;
            size--;
        }
    }
    Node *getNodeAt(int index)
    {

        Node *temp = new Node();
        temp = head;
        for (int i = 1; i <= index; i++)
        {
            temp = temp->next;
        }
        return temp;
    }
    void reverseDI()
    {
        int li = 0;
        int ri = size - 1;
        while (li < ri)
        {
            Node *left = getNodeAt(li);
            Node *right = getNodeAt(ri);

            int temp = left->data;
            left->data = right->data;
            right->data = temp;

            li++;
            ri--;
        }
    }
    void reversePI()
    {
        Node *prev = NULL;
        Node *curr = head;

        while (curr != NULL)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        Node *temp = head;
        head = tail;
        tail = temp;
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
        else if ("addFirst" == str.substr(0, 8))
        {
            int val = stoi(str.substr(9));
            list.addFirst(val);
        }
        else if ("addAt" == str.substr(0, 5))
        {

            stringstream ss;
            string out;
            ss << str;
            ss >> out;
            ss >> out;
            int index = stoi(out);
            ss >> out;
            int val = stoi(out);
            list.addAt(index, val);
        }
        else if ("removeLast" == str)
        {
            list.removeLast();
        }
        else if ("removeAt" == str.substr(0, 8))
        {

            int index = stoi(str.substr(9));
            list.removeAt(index);
        }
        else if ("reverseDI" == str)
        {
            list.reverseDI();
        }
        else if ("reversePI" == str)
        {
            list.reversePI();
        }
    }
    return 0;
}
