// 1. You are given a partially written GenericTree class.
// 2. You are required to complete the body of size function.
// The function is expected to count the number of nodes in the tree and return it.
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
class Node
{
public:
    long long data;
    vector<Node *> children;
};
static Node *construct(vector<long long> arr)
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
    vector<long long> arr(n);
    for (long long &e : arr)
    {
        cin >> e;
    }
    Node *root = construct(arr);
    int sz = size(root);
    cout << sz << endl;
    return 0;
}