/*Construct Tree from Postorder and Inorder
Given Postorder and Inorder traversal of a binary tree, create the binary tree associated with the traversals.You just need to construct the tree and return the root.
Note: Assume binary tree contains only unique elements.
Input format :

Line 1 : n (Total number of nodes in binary tree)

Line 2 : Post order traversal

Line 3 : Inorder Traversal

Output Format :

Elements are printed level wise, each level in new line (separated by space).

Sample Input :
8
8 4 5 2 6 7 3 1
4 8 2 5 1 6 3 7
Sample Output :
1 
2 3 
4 5 6 7 
8*/

#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

BinaryTreeNode<int> *cons(int *post, int postl, int *in, int inl)
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(post[postl - 1]);
    if (postl == 0)
    {
        return NULL;
    }
    if (postl == 1)
    {
        return root;
    }
    int rootIndex = 0;
    while (in[rootIndex] != root->data)
    {
        rootIndex++;
    }

    int llen = rootIndex;
    int rlen = inl - rootIndex - 1;

    root->left = cons(post, llen, in, llen);
    root->right = cons(post + llen, rlen, in + llen + 1, rlen);

    return root;
}