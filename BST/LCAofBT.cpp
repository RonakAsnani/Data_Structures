/*LCA of Binary Tree
Given a binary tree and two nodes, find LCA (Lowest Common Ancestor) of the given two nodes in Binary Tree. Read about LCA if you are having doubts about the definition.
If out of 2 nodes only one node is present, return that node.
If both are not present, return -1.
Input format :
Line 1 :  Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 2 : Two integers, Node 1 and Node 2 (separated by space)
Output Format :
LCA
Constraints :
1 <= N <= 1000
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
2 10
Sample Output 1:
10
Sample Input 2:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
2 6
Sample Output 2:
5
Sample Input 3:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
12 78
Sample Output 3:
-1*/

#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

int LCA(BinaryTreeNode<int> *root, int data1, int data2)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == data1 || root->data == data2)
    {
        return root->data;
    }
    else
    {
        int left = LCA(root->left, data1, data2);
        int right = LCA(root->right, data1, data2);

        if (left == NULL && right != NULL)
        {
            return right;
        }
        else if (right == NULL && left != NULL)
        {
            return left;
        }
        else if (right == NULL && left == NULL)
        {
            return -1;
        }
        else
        {
            return root->data;
        }
    }
}