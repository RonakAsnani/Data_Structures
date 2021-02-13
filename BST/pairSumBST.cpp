/*Pair sum in a BST
Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space only O(log n).
Assume BST contains all unique elements.
Note: In a pair, print the smaller element first.
Input format:

Line 1: Elements in the level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Line 2: S

Output format: Each pair in a different line (pair elements separated by space)

Sample Input :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
Sample Output
2 10
5 7
*/

// same as bt
// this one is incorrect

#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

void printPair(BinaryTreeNode<int> *root, int s, int x)
{
    if (root == NULL)
    {
        return;
    }
    if (s > x + root->data)
    {
        printPair(root->right, s, x);
        return;
    }
    else if (s < x + root->data)
    {
        printPair(root->left, s, x);
        return;
    }
    else if (s == x + root->data)
    {
        if (x > root->data)
        {
            cout << root->data << " " << x << endl;
        }
        else
        {
            cout << x << " " << root->data << endl;
        }
        return;
    }
    printPair(root->left, s, root->left->data);
    printPair(root->right, s, root->right->data);
}
void prin(BinaryTreeNode<int> *root, int s)
{
    printPair(root, s, root->data);
}
