// 1. You are given a partially written GenericTree class.
// 2. You are required to complete the body of lca function.
// The function is expected to return the lowest common ancestor of two data values that are passed to it.
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
static void levelOrderLinewise(Node *node)
{
    queue<Node *> mq, cq;
    mq.push(node);
    while (mq.size() > 0)
    {
        node = mq.front();
        mq.pop();
        cout << node->data << " ";
        for (Node *child : node->children)
        {
            cq.push(child);
        }
        if (mq.size() == 0)
        {
            mq = cq;
            cq = queue<Node *>();
            cout << endl;
        }
    }
}
static void levelOrderZigZag(Node *node)
{
    stack<Node *> mq, cq;
    mq.push(node);
    int level = 1;
    while (mq.size() > 0)
    {
        node = mq.top();
        mq.pop();
        cout << node->data << " ";
        if (level % 2 == 1)
        {
            for (int i = 0; i < node->children.size(); i++)
            {
                Node *child = node->children[i];
                cq.push(child);
            }
        }
        else
        {
            for (int i = node->children.size() - 1; i >= 0; i--)
            {
                Node *child = node->children[i];
                cq.push(child);
            }
        }
        if (mq.size() == 0)
        {
            mq = cq;
            cq = stack<Node *>();
            cout << endl;
            level++;
        }
    }
}
static void mirror(Node *node)
{

    for (Node *child : node->children)
    {
        mirror(child);
    }
    reverse(node->children.begin(), node->children.end());
}
static void removeLeaves(Node *node)
{
    for (int i = node->children.size() - 1; i >= 0; i--)
    {
        Node *child = node->children[i];
        if (child->children.size() == 0)
        {
            node->children.erase(node->children.begin() + i);
        }
    }
    for (Node *child : node->children)
    {
        removeLeaves(child);
    }
}
static Node *getTail(Node *node)
{
    while (node->children.size() == 1)
    {
        node = node->children[0];
    }
    return node;
}
static void linearize(Node *node)
{
    for (Node *child : node->children)
    {
        linearize(child);
    }
    while (node->children.size() > 1)
    {
        Node *lc = node->children[node->children.size() - 1];
        node->children.erase(node->children.begin() + node->children.size() - 1);
        Node *slc = node->children[node->children.size() - 1];
        Node *slct = getTail(slc);
        slct->children.push_back(lc);
    }
}
static bool findKey(Node *node, int key)
{
    if (node->data == key)
    {
        return true;
    }
    bool flag;
    for (Node *child : node->children)
    {
        flag = findKey(child, key);
        if (flag)
        {
            return true;
        }
    }
    return false;
}
static vector<int> nodeToRoothPath(Node *node, int key)
{
    if (node->data == key)
    {
        vector<int> list;
        list.push_back(node->data);
        return list;
    }
    for (Node *child : node->children)
    {
        vector<int> ptc = nodeToRoothPath(child, key);
        if (ptc.size() > 0)
        {
            ptc.push_back(node->data);
            return ptc;
        }
    }
    return vector<int>();
}
static int lowestCommonAncestor(Node *node, int val1, int val2)
{
    vector<int> p1 = nodeToRoothPath(node, val1);
    vector<int> p2 = nodeToRoothPath(node, val2);
    int i = p1.size() - 1;
    int j = p2.size() - 1;
    while (i >= 0 && j >= 0 && p1[i] == p2[j])
    {
        i--;
        j--;
    }
    i++;
    j++;
    return p1[i];
}
static void display(Node *node)
{
    string str = to_string(node->data) + " -> ";
    for (Node *child : node->children)
    {
        str += to_string(child->data) + ", ";
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
    int val1;
    cin >> val1;
    int val2;
    cin >> val2;
    Node *root = construct(arr);
    cout << lowestCommonAncestor(root, val1, val2);
    return 0;
}