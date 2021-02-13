/*Find Path in BST
Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST). Return null otherwise.Assume that BST contains all unique elements.
Sample Input :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
Sample Output :
2
5
8*/

#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

vector<int> *path(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        vector<int> *v = new vector<int>();
        v->push_back(root->data);
        return v;
    }
    vector<int> *left = path(root->left, data);
    vector<int> *right = path(root->right, data);

    if (left != NULL)
    {
        left->push_back(root->data);
        return left;
    }
    if (right != NULL)
    {
        right->push_back(root->data);
        return right;
    }
    return NULL;
}