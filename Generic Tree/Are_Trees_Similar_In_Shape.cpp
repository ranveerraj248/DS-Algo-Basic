// 1. You are given a partially written GenericTree class.
// 2. You are required to complete the body of areSimilar function.
// The function is expected to check if the two trees passed to it are similar in shape or not.
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
static int distanceBtnTwoNodes(Node *node, int val1, int val2)
{
    vector<int> p1 = nodeToRoothPath(node, val1);
    vector<int> p2 = nodeToRoothPath(node, val2);
    int i = p1.size() - 1;
    int j = p2.size() - 1;
    while (i >= 0 && j >= 0 && p1[i] == p2[j])
    {
        p1.erase(p1.begin() + i);
        p2.erase(p2.begin() + j);
        i--;
        j--;
    }
    int ans = p1.size() + p2.size();
    return abs(ans);
}
static bool similar(Node *root1, Node *root2)
{
    if (root1->children.size() != root2->children.size())
    {
        return false;
    }
    for (int i = 0; i < root1->children.size(); i++)
    {
        Node *child1 = root1->children[i];
        Node *child2 = root2->children[i];
        if (similar(child1, child2) == false)
        {
            return false;
        }
    }
    return true;
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
    Node *root = construct(arr);
    int n2;
    cin >> n2;
    vector<int> arr2(n2);
    for (int &e : arr2)
    {
        cin >> e;
    }
    Node *root2 = construct(arr2);
    if (similar(root, root2))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}