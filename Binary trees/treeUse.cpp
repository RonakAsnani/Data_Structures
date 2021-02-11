#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        cout << front->data << ": ";
        if (front->left != NULL)
        {
            cout << "L" << front->left->data;
            q.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << "R" << front->right->data;
            q.push(front->right);
        }
        cout << endl;
    }
}

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data: " << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    queue<BinaryTreeNode<int> *> q;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChild;
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChild);
            front->left = child;
            q.push(child);
        }

        cout << "Enter right child of " << front->data << endl;
        int rightChild;
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChild);
            front->right = child;
            q.push(child);
        }
    }
    return root;
}
BinaryTreeNode<int> *cons(int *post, int postl, int *in, int inl)
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(post[postl - 1]);
    if (postl == 0)
    {
        return NULL;
    }
    if (postl == 1)
    {
        return root;
    }
    int rootIndex = 0;
    while (in[rootIndex] != root->data)
    {
        rootIndex++;
    }

    int llen = rootIndex;
    int rlen = inl - rootIndex - 1;

    root->left = cons(post, llen, in, llen);
    root->right = cons(post + llen, rlen, in + llen + 1, rlen);

    return root;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    // root->left = node1;
    // root->right = node2;
    // printTree(root);
    // delete (root);
    // return 0;
    int n;
    cin >> n;
    int *pre = new int[n];
    int *in = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    BinaryTreeNode<int> *root = cons(pre, n, in, n);
    printLevelWise(root);
}