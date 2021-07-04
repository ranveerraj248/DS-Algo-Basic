// 1. You are given a partially written LinkedList class.
// 2. Here is a list of existing functions:
//      2.1 addLast - adds a new element with given value to the end of Linked List
//      2.2. display - Prints the elements of linked list from front to end in a single line.
//      All elements are separated by space
//     2.3. size - Returns the number of elements in the linked list.
//     2.4. removeFirst - Removes the first element from Linked List.
//     2.5. getFirst - Returns the data of first element.
//     2.6. getLast - Returns the data of last element.
//     2.7. getAt - Returns the data of element available at the index passed.
//     2.8. addFirst - adds a new element with given value in front of linked list.
//    2.9. addAt - adds a new element at a given index.
//    2.10. removeLast - removes the last element of linked list.
//    2.11. removeAt - remove an element at a given index
//    2.12 kthFromLast - return kth node from end of linked list.
// 3. You are required to complete the body of mid function.
//    The function should be an iterative function and should return the mid of linked list.
//    Also, make sure to not use size data member directly or indirectly (by calculating size via making a traversal).
//    In linked list of odd size, mid is unambigous. In linked list of even size, consider end of first half as mid.
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
    Node *head;
    Node *tail;
    int size;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void addLast(int val)
    {
        Node *temp = new Node();
        temp->data = val;
        temp->next = NULL;

        if (size == 0)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    int Size()
    {
        return size;
    }
    void display()
    {
        for (Node *temp = head; temp != NULL; temp = temp->next)
        {
            cout << temp->data << " ";
        }
        cout << endl;
    }
    void removeFirst()
    {
        if (size == 0)
        {
            cout << "List is empty" << endl;
        }
        else if (size == 1)
        {
            head = tail = NULL;
            size = 0;
        }
        else
        {
            head = head->next;
            size--;
        }
    }
    int getFirst()
    {
        if (size == 0)
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
        if (size == 0)
        {
            cout << "List is empty" << endl;
            return -1;
        }
        else
        {
            return tail->data;
        }
    }
    int getAt(int idx)
    {
        if (size == 0)
        {
            cout << "List is empty" << endl;
            return -1;
        }
        else if (idx < 0 || idx >= size)
        {
            cout << "Invalid arguments" << endl;
            return -1;
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < idx; i++)
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
        temp->next = head;
        head = temp;

        if (size == 0)
        {
            tail = temp;
        }

        size++;
    }
    void addAt(int idx, int val)
    {
        if (idx < 0 || idx > size)
        {
            cout << "Invalid arguments" << endl;
        }
        else if (idx == 0)
        {
            addFirst(val);
        }
        else if (idx == size)
        {
            addLast(val);
        }
        else
        {
            Node *node = new Node();
            node->data = val;

            Node *temp = head;
            for (int i = 0; i < idx - 1; i++)
            {
                temp = temp->next;
            }
            node->next = temp->next;

            temp->next = node;
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
            size = 0;
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < size - 2; i++)
            {
                temp = temp->next;
            }

            tail = temp;
            tail->next = NULL;
            size--;
        }
    }
    void removeAt(int idx)
    {
        if (idx < 0 || idx >= size)
        {
            cout << "Invalid arguments" << endl;
        }
        else if (idx == 0)
        {
            removeFirst();
        }
        else if (idx == size - 1)
        {
            removeLast();
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < idx - 1; i++)
            {
                temp = temp->next;
            }

            temp->next = temp->next->next;
            size--;
        }
    }
    Node *getNodeAt(int idx)
    {
        Node *temp = head;
        for (int i = 0; i < idx; i++)
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
        if (size <= 1)
        {
            return;
        }

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
    int kthFromLast(int k)
    {
        Node *slow = head;
        Node *fast = head;
        for (int i = 0; i < k; i++)
        {
            fast = fast->next;
        }

        while (fast != tail)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow->data;
    }

    int mid()
    {
        Node *f = head;
        Node *s = head;

        while (f->next != NULL && f->next->next != NULL)
        {
            f = f->next->next;
            s = s->next;
        }

        return s->data;
    }
    static LinkedList mergeTwoSortedLists(LinkedList l1, LinkedList l2)
    {
        Node *one = l1.head;
        Node *two = l2.head;
        LinkedList res;
        while (one != NULL && two != NULL)
        {
            if (one->data < two->data)
            {
                res.addLast(one->data);
                one = one->next;
            }
            else
            {
                res.addLast(two->data);
                two = two->next;
            }
        }
        while (one != NULL)
        {
            res.addLast(one->data);
            one = one->next;
        }
        while (two != NULL)
        {
            res.addLast(two->data);
            two = two->next;
        }
        return res;
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
        else if ("kthFromEnd" == str.substr(0, 10))
        {
            int val = stoi(str.substr(11));
            cout << list.kthFromLast(val) << endl;
        }
        else if ("mid" == str)
        {
            cout << list.mid() << endl;
        }
    }
    return 0;
}
