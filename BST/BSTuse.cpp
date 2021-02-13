#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

int largestBST(BinaryTreeNode<int> *root, int min, int max, int height)
{

    if (root == NULL)
    {
        return 0;
    }
    if (root->data < root->right->data && root->data > root->left->data)
    {
        if (root->data > min && root->data < max)
        {
            int left = largestBST(root->left, min, root->data + 1, height);
            int right = largestBST(root->right, root->data, max, height);
            return height + 1 + left + right;
        }
    }
    else
    {
        int left = largestBST(root->left, min, root->data + 1, height);
        int right = largestBST(root->right, root->data, max, height);
        return left + right;
    }
    return height;
}

int bst(BinaryTreeNode<int> *root)
{
    int min = INT_MIN;
    int max = INT_MAX;
    int height = 0;
    return largestBST(root, min, max, 0);
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

    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << bst(root);
}