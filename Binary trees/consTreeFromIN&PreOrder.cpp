/*
Code: Construct Tree from Preorder and Inorder
Given Preorder and Inorder traversal of a binary tree, create the binary tree associated with the traversals.You just need to construct the tree and return the root.
Note: Assume binary tree contains only unique elements.
Input format :

Line 1 : n (Total number of nodes in binary tree)

Line 2 : Pre order traversal

Line 3 : Inorder Traversal

Output Format :

Elements are printed level wise, each level in new line (separated by space).

Sample Input :
12
1 2 3 4 15 5 6 7 8 10 9 12
4 15 3 2 5 1 6 10 8 7 9 12
Sample Output :
1 
2 6 
3 5 7 
4 8 9 
15 10 12*/

#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

BinaryTreeNode<int> *cons(int *pre, int prel, int *in, int inl)
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(pre[0]);
    if (prel == 0)
    {
        return NULL;
    }
    if (prel == 1)
    {
        return root;
    }
    int rootIndex = 0;
    while (in[rootIndex] != root->data)
    {
        rootIndex++;
    }
    int llen = rootIndex - 1;
    int rlen = inl - rootIndex - 1;

    root->left = cons(pre + 1, llen, in, llen);
    root->right = cons(pre + llen + 1, rlen, in + llen + 1, rlen);

    return root;
}
