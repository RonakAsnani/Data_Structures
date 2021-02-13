#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

void printDist(BinaryTreeNode<int> *root, int n, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data != n)
    {
        printDist(root->left, n, k);
        printDist(root->right, n, k);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            if (k == 0)
            {
                cout << root->data << endl;
            }
            return;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            if (k == 0)
            {
                cout << root->data << endl;
                return;
            }
            else
            {
                printDist(root->left, root->left->data, k - 1);
            }
        }
        else if (root->left == NULL && root->right != NULL)
        {
            if (k == 0)
            {
                cout << root->data << endl;
                return;
            }
            else
            {
                printDist(root->right, root->right->data, k - 1);
            }
        }
        else if (root->left != NULL && root->right != NULL)
        {
            if (k == 0)
            {
                cout << root->data << endl;
                return;
            }
            else
            {
                printDist(root->left, root->left->data, k - 1);
                printDist(root->right, root->right->data, k - 1);
            }
        }
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

int main()
{
    int n, k;
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cin >> n;
    cin >> k;
    printDist(root, n, k);
}