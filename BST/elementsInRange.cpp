/*Code: Print Elements in Range
Given a Binary Search Tree and two integers k1 and k2, find and print the elements which are in range k1 and k2 (both inclusive).
Print the elements in increasing order.
Sample Input :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
6 10
Sample Output :
6 7 8 10*/

#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

void printInOrder(BinaryTreeNode<int> *root, int small, int large)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data > large && root->data > small)
    {
        printInOrder(root->left, small, large);
    }
    if (root->data < large && root->data < small)
    {
        printInOrder(root->right, small, large);
    }
    if (root->data < large && root->data > small)
    {
        printInOrder(root->left, small, large);
        cout << root->data << " ";
        printInOrder(root->right, small, large);
    }
    if (root->data > large && root->data < small)
    {
        return;
    }
}