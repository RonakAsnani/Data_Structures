#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

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

int ma(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(ma(root->left), ma(root->right)));
}
int mi(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    return min(root->data, min(mi(root->left), mi(root->right)));
}

bool ifBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }

    int leftMax = ma(root->left);
    int rightmin = mi(root->right);

    bool out = (root->data > leftMax) && (root->data <= rightmin) && ifBST(root->left) && ifBST(root->right);

    return out;
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << ifBST(root);
    delete (root);
}