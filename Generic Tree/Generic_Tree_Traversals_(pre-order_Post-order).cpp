// 1. You are given a partially written GenericTree class.
// 2. You are required to complete the body of traversals function. The function is expected to visit every node. While traversing the function must print following content in different situations.
//    2.1. When the control reaches the node for the first time -> "Node Pre" node.data.
//    2.2. Before the control leaves for a child node from a node -> "Edge Pre"
//    node.data--child.data.
//    2.3. After the control comes back to a node from a child -> "Edge Post" node.data-
//    -child.data.
//     2.4. When the control is about to leave node, after the children have been visited
//     -> "Node Post" node.data.
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <climits>
#include <algorithm>
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
    traversal(root);
    return 0;
}