/*Second Largest Element In Tree
Given a generic tree, find and return the node with second largest value in given tree. Return NULL if no node with required value is present.
Input format :
Line 1 : Elements in level order form separated by space (as per done in class). Order is -
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Output Format :
Second Largest node data
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40*/

#include <bits/stdc++.h>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    TreeNode<int> *m = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *small = maxDataNode(root->children[i]);
        if (m->data < small->data)
        {
            m = small;
        }
    }
    return m;
}

TreeNode<int> *secMax(TreeNode<int> *root)
{
    TreeNode<int> *x = maxDataNode(root);
    TreeNode<int> *m = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *small = maxDataNode(root->children[i]);
        if (m->data < small->data && small->data < x->data)
        {
            m = small;
        }
    }
    return m;
}
