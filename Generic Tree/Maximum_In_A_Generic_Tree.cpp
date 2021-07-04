// 1. You are given a partially written GenericTree class.
// 2. You are required to complete the body of max function. The function is expected to find the node with maximum value and return it.
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <climits>
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
    int mx = max(root);
    cout << mx << endl;
    return 0;
}