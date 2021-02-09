#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

void preorder(TreeNode<int> *root)
{
    if (root = NULL)
    {
        return;
    }
    cout << root->data << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}