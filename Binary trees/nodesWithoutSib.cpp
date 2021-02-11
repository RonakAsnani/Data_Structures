/*Nodes without sibling
Given a binary tree, print all nodes that don’t have a sibling.
Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
9*/

#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

void print(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right != NULL)
    {
        cout << root->data;
        print(root->right);
    }
    if (root->left != NULL && root->right == NULL)
    {
        cout << root->data;
        print(root->left);
    }
    if (root->left != NULL && root->right != NULL)
    {
        print(root->left);
        print(root->right);
    }
    return;
}