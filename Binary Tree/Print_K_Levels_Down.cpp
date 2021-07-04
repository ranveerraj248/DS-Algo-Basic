// 1. You are given a partially written BinaryTree class.
// 2. You are given a value k.
// 3. You are required to complete the body of printKLevelsDown function.
// The function is expected to print in different lines all nodes which are k level deep.
// Use preorder for printing.
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
static void orderTraversal(Node *node)
{
    string pre = "";
    string in = "";
    string post = "";
    stack<Pair *> st;
    Pair *rtp = new Pair(node, 1);
    st.push(rtp);
    while (st.size() > 0)
    {
        Pair *top = st.top();
        if (top->state == 1)
        { // pre, s++, left
            pre += to_string(top->node->data) + " ";
            top->state++;

            if (top->node->left != NULL)
            {
                Pair *lp = new Pair(top->node->left, 1);
                st.push(lp);
            }
        }
        else if (top->state == 2)
        { // in, s++, right
            in += to_string(top->node->data) + " ";
            top->state++;

            if (top->node->right != NULL)
            {
                Pair *rp = new Pair(top->node->right, 1);
                st.push(rp);
            }
        }
        else
        { // post, pop
            post += to_string(top->node->data) + " ";
            st.pop();
        }
    }

    cout << pre << endl;
    cout << in << endl;
    cout << post << endl;
}
static vector<int> path;
static bool find(Node *node, int key)
{
    if (node == NULL)
    {
        return false;
    }
    if (node->data == key)
    {
        path.push_back(node->data);
        return true;
    }
    bool filc = find(node->left, key);
    if (filc)
    {
        path.push_back(node->data);
        return true;
    }
    bool firc = find(node->right, key);
    if (firc)
    {
        path.push_back(node->data);
        return true;
    }
    return false;
}
static void printKLevel(Node *node, int level)
{
    if (node == NULL || level < 0)
    {
        return;
    }
    if (level == 0)
    {
        cout << node->data << endl;
    }
    printKLevel(node->left, level - 1);
    printKLevel(node->right, level - 1);
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
    int level;
    cin >> level;
    Node *root = construct(arr);
    printKLevel(root, level);
    return 0;
}