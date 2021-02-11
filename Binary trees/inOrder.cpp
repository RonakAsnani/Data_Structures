#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

void printInOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}