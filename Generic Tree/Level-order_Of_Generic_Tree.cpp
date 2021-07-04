// 1. You are given a partially written GenericTree class.
// 2. You are required to complete the body of levelorder function.
// The function is expected to visit every node in "levelorder fashion".
// Please check the question video for more details.

/**************************************************************
 * remove / print/ add child 
**************************************************************/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    vector<Node *> children;
};
static Node *construct(vector<int> arr)
{
    Node *root = NULL;

    stack<Node *> st;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == -1)
        {
            st.pop();
        }
        else
        {
            Node *t = new Node;
            t->data = arr[i];

            if (st.size() > 0)
            {
                st.top()->children.push_back(t);
            }
            else
            {
                root = t;
            }

            st.push(t);
        }
    }

    return root;
}
static int size(Node *node)
{
    int s = 0;
    for (Node *child : node->children)
    {
        int temp = size(child);
        s += temp;
    }
    s = s + 1;
    return s;
}
static int max(Node *node)
{
    int maxm = INT_MIN;
    for (Node *child : node->children)
    {
        int temp = max(child);
        if (temp > maxm)
        {
            maxm = temp;
        }
    }
    if (maxm < node->data)
    {
        maxm = node->data;
    }
    return maxm;
}
static int height(Node *node)
{
    int ht = -1;
    for (Node *child : node->children)
    {
        int temp = height(child);
        ht = max(ht, temp);
    }
    ht += 1;
    return ht;
}
static void traversal(Node *node)
{
    cout << "Node Pre " << node->data << endl;
    for (Node *child : node->children)
    {
        cout << "Edge Pre " << node->data << "--" << child->data << endl;
        traversal(child);
        cout << "Edge Post " << node->data << "--" << child->data << endl;
    }
    cout << "Node Post " << node->data << endl;
}
static void levelOrder(Node *node)
{
    queue<Node *> q;
    q.push(node);
    while (q.size() > 0)
    {
        node = q.front();
        q.pop();
        cout << node->data << " ";
        for (Node *child : node->children)
        {
            q.push(child);
        }
    }
    cout << ".";
}
static void display(Node *node)
{
    string str = node->data + " -> ";
    for (Node *child : node->children)
    {
        str += child->data + ", ";
    }
    str += ".";
    cout << str << endl;

    for (Node *child : node->children)
    {
        display(child);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &e : arr)
    {
        cin >> e;
    }
    Node *root = construct(arr);
    levelOrder(root);
    return 0;
}