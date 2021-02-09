/*  
Code : Count leaf nodes
Given a generic tree, count and return the number of leaf nodes present in the given tree.
Input format :
Elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Output Format :
Count of leaf nodes
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
4*/

#include <bits/stdc++.h>
#include <queue>
#include "TreeNode.h"
using namespace std;

int printLeaf(TreeNode<int> *root)
{
    if (root->children.empty())
    {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += printLeaf(root->children[i]);
    }
    return ans;
}