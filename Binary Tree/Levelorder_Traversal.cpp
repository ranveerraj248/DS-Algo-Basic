// 1. You are given a partially written BinaryTree class.
// 2. You are required to complete the body of levelorder function.
// The function is expected to print tree level by level, left to right.
// Each level must be on a separate line and elements of same level should be separated by space
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>
#include <queue>
#include <climits>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
class Pair
{
public:
    Node *node;
    int state;
    Pair(Node *node, int state)
    {
        this->node = node;
        this->state = state;
    }
};
static Node *construct(vector<int> arr)
{
    Node *root = new Node(arr[0], NULL, NULL);
    Pair *rtp = new Pair(root, 1);

    stack<Pair *> st;
    st.push(rtp);

    int idx = 0;
    while (st.size() > 0)
    {
        Pair *top = st.top();
        if (top->state == 1)
        {
            idx++;
            if (arr[idx] != -1)
            {
                top->node->left = new Node(arr[idx], NULL, NULL);
                Pair *lp = new Pair(top->node->left, 1);
                st.push(lp);
            }
            else
            {
                top->node->left = NULL;
            }
            top->state++;
        }
        else if (top->state == 2)
        {
            idx++;
            if (arr[idx] != -1)
            {
                top->node->right = new Node(arr[idx], NULL, NULL);
                Pair *rp = new Pair(top->node->right, 1);
                st.push(rp);
            }
            else
            {
                top->node->right = NULL;
            }
            top->state++;
        }
        else
        {
            st.pop();
        }
    }
    return root;
}
static int size(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int ls = size(node->left);
    int rs = size(node->right);
    int ts = ls + rs + 1;
    return ts;
}
static int sum(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int lsm = sum(node->left);
    int rsm = sum(node->right);
    int tsm = lsm + rsm + node->data;
    return tsm;
}
static int maxm(Node *node)
{
    if (node == NULL)
    {
        return INT_MIN;
    }
    int lm = maxm(node->left);
    int rm = maxm(node->right);
    int tm = max(node->data, max(lm, rm));
    return tm;
}
static int height(Node *node)
{
    if (node == NULL)
    {
        return -1;
    }
    int lh = height(node->left);
    int rh = height(node->right);
    int th = max(lh, rh) + 1;
    return th;
}
static void display(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    string str = "";
    str += node->left == NULL ? "." : to_string(node->left->data) + "";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right == NULL ? "." : to_string(node->right->data) + "";

    cout << str << endl;
    display(node->left);
    display(node->right);
}
static void levelorderTraversal(Node *node)
{
    queue<Node *> mq;
    mq.push(node);
    while (mq.size() > 0)
    {
        int count = mq.size();
        for (int i = 0; i < count; i++)
        {
            node = mq.front();
            mq.pop();
            cout << node->data << " ";
            if (node->left != NULL)
            {
                mq.push(node->left);
            }
            if (node->right != NULL)
            {
                mq.push(node->right);
            }
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    string str;
    cin.ignore();
    getline(cin, str);
    vector<int> arr;
    stringstream ss;
    ss << str;
    string data;
    while (ss >> data)
    {
        if (data == "n")
        {
            arr.push_back(-1);
        }
        else
        {
            int val = stoi(data);
            arr.push_back(val);
        }
    }
    Node *root = construct(arr);
    levelorderTraversal(root);
    return 0;
}