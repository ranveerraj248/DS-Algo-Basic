// 1. You are given a partially written LinkedList class.
// 2. You are required to complete the body of IsPalindrome function.
// The function is expected to check if the linked list is a palindrome or not and return true or false accordingly.
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
    static Node *midNode(Node *head, Node *tail)
    {
        Node *f = head;
        Node *s = head;
        while (f != tail && f->next != tail)
        {
            f = f->next->next;
            s = s->next;
        }
        return s;
    }
    static LinkedList mergeSort(Node *head, Node *tail)
    {
        if (head == tail)
        {
            LinkedList baseResult;
            baseResult.addLast(head->data);
            return baseResult;
        }
        Node *mid = midNode(head, tail);
        LinkedList fsh = mergeSort(head, mid);
        LinkedList ssh = mergeSort(mid->next, tail);
        LinkedList result = LinkedList::mergeTwoSortedLists(fsh, ssh);
        return result;
    }
    void removeDuplicates()
    {
        LinkedList res;
        while (this->Size() > 0)
        {
            int val = this->getFirst();
            this->removeFirst();

            if (res.Size() == 0 || res.tail->data != val)
            {
                res.addLast(val);
            }
        }
        this->head = res.head;
        this->tail = res.tail;
        this->size = res.size;
    }
    void oddEven()
    {
        LinkedList odd;
        LinkedList even;
        while (this->Size() > 0)
        {
            int val = this->getFirst();
            this->removeFirst();
            if ((val % 2) == 0)
            {
                even.addLast(val);
            }
            else
            {
                odd.addLast(val);
            }
        }
        if (odd.Size() > 0 && even.Size() > 0)
        {
            odd.tail->next = even.head;
            this->head = odd.head;
            this->tail = even.tail;
            this->size = odd.size + even.size;
        }
        else if (odd.Size() > 0)
        {
            this->head = odd.head;
            this->tail = odd.tail;
            this->size = odd.size;
        }
        else if (even.Size() > 0)
        {
            this->head = even.head;
            this->tail = even.tail;
            this->size = even.size;
        }
    }
    void kReverse(int k)
    {
        LinkedList prev;

        while (this->Size() > 0)
        {
            LinkedList curr;
            if (this->Size() >= k)
            {
                for (int i = 0; i < k; i++)
                {
                    int val = this->getFirst();
                    this->removeFirst();
                    curr.addFirst(val);
                }
            }
            else
            {
                int s = this->Size();
                for (int i = 0; i < s; i++)
                {
                    int val = this->getFirst();
                    this->removeFirst();
                    curr.addLast(val);
                }
            }
            if (prev.Size() == 0)
            {
                prev = curr;
            }
            else
            {
                prev.tail->next = curr.head;
                prev.tail = curr.tail;
                prev.size += curr.size;
            }
        }
        this->head = prev.head;
        this->tail = prev.tail;
        this->size = prev.size;
    }
    void displayReverseHelper(Node *node)
    {
        if (node == tail)
        {
            cout << node->data << " ";
            return;
        }
        Node *temp = node->next;
        displayReverseHelper(temp);
        cout << node->data << " ";
    }

    void displayReverse()
    {
        displayReverseHelper(head);
        cout << endl;
    }
    void reversePRHelper(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        reversePRHelper(node->next);
        if (node == tail)
        {
        }
        else
        {
            node->next->next = node;
        }
    }

    void reversePR()
    {
        reversePRHelper(head);
        head->next = NULL;
        Node *temp = head;
        head = tail;
        tail = temp;
    }
    bool IsPalindromeHealper(Node *right)
    {
        if (right == NULL)
        {
            return true;
        }
        bool rres = IsPalindromeHealper(right->next);
        if (rres == false)
        {
            return false;
        }
        else if (pleft->data != right->data)
        {
            return false;
        }
        else
        {
            pleft = pleft->next;
            return true;
        }
    }
    Node *pleft;
    bool IsPalindrome()
    {
        pleft = head;
        return IsPalindromeHealper(head);
    }
};
int main()
{
    int n1;
    cin >> n1;
    LinkedList l1;
    for (int i = 0; i < n1; i++)
    {
        int d;
        cin >> d;
        l1.addLast(d);
    }
    if (l1.IsPalindrome())
    {

        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}