/*Preorder Binary Tree
Given a binary tree, print the preorder traversal of given tree.
Pre-order traversal is: Root LeftChild RightChild
Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output Format :
Pre-order traversal, elements separated by space
Sample Input :
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output :
8 3 1 6 4 7 10 14 13
*/

#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

void preOrderBT(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderBT(root->left);
    preOrderBT(root->right);
    return;
}