#include <bits/stdc++.h>
#include <queue>
#include "TreeNode.h"
using namespace std;

void printAtK(TreeNode<int> *root, int k)
{
    if (root = NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << endl;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtK(root->children[i], k - 1);
    }
}