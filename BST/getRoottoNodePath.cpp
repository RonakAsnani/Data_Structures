#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

vector<int> *path(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data = data)
    {
        vector<int> *v = new vector<int>();
        v->push_back(root->data);
        return v;
    }
    vector<int> *left = path(root->left, data);
    if (left != NULL)
    {
        left->push_back(root->data);
    }

    vector<int> *right = path(root->right, data);
    if (right != NULL)
    {
        right->push_back(root->data);
    }
    else
    {
        return NULL;
    }
}