#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

int countNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int x = countNodes(root->left);
    int y = countNodes(root->right);

    return x + y + 1;
}