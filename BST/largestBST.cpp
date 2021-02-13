/*Largest BST
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree.
Return the height of largest BST.
Input format :

Line 1 : Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2*/

// repeat

#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

bool isBST(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data < min || root->data > max)
    {
        return false;
    }

    bool left = isBST(root->left, min, root->data - 1);
    bool right = isBST(root->right, root->data, max);

    return left && right;
}

int bst(BinaryTreeNode<int> *root)
{
    if (isBST(root))
    {
        return height(root);
    }
    else
    {
        int left = isBST(root->left);
        int right = isBST(root->right);
        return max(height(root->left), height(root->right));
    }
}