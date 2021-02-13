/*LCA of BST
Given a binary search tree and two nodes, find LCA(Lowest Common Ancestor) of the given two nodes in the BST. Read about LCA if you are having doubts about the definition.
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
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2 10
Sample Output 1:
8
Sample Input 2:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2 6
Sample Output 2:
5
Sample Input 3:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12 78
Sample Output 3:
-1*/

// repeat

#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

int LCA(BinaryTreeNode<int> *root, int data1, int data2)
{
    if (root == NULL)
    {
        return -1;
    }
    else if (root->data == data1)
    {
        return root->data;
    }
    else if (root->data == data2)
    {
        return root->data;
    }
    else if (root->data > data1 && root->data > data2)
    {
        return LCA(root->left, data1, data2);
    }
    else if (root->data < data1 && root->data < data2)
    {
        return LCA(root->right, data1, data2);
    }
    else
    {
        int l = LCA(root->left, data1, data2);
        int r = LCA(root->right, data1, data2);
        if (l == -1 && r == -1)
        {
            return -1;
        }
        else if (l != -1 && r == -1)
        {
            return l;
        }
        else if (r != -1 && r == -1)
        {
            return r;
        }
        else
        {
            return root->data;
        }
    }
}
// done on leetcode
/*TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        int data1 = p->val;
        int data2 = q->val;
        
        if(root->val == data1 || root->val == data2){
            return root;
        }else if(root->val > data1 && root->val > data2){
            return lowestCommonAncestor(root->left,p,q);
        }else if(root->val < data1 && root->val < data2){
            return lowestCommonAncestor(root->right,p,q);
        }else{
            TreeNode* l =  lowestCommonAncestor(root->left,p,q);
            TreeNode* r =  lowestCommonAncestor(root->right,p,q);
            
            if(l == NULL && r == NULL){
                return NULL;
            }else if(l != NULL && r == NULL){
                return l;
            }else if(l == NULL && r != NULL){
                return r;
            }else{
                return root;
            }
        }
    }
};*/