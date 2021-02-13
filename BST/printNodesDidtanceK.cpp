/*Print nodes at distance k from node
Given a binary tree, a node and an integer K, print nodes which are at K distance from the the given node.
Input format :

Line 1 : Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Line 2 : Node

Line 3 : K

Output format : Answer nodes in different line

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
3
1
Sample Output :
9
6*/

//// wrongggg

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