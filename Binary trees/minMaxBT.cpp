/*Min and Max of Binary Tree
Given a binary tree, find and return the min and max data value of given binary tree.
Return the output as an object of PairAns class, which is already created.
Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output Format :
Max and min (separated by space)
Sample Input :
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output :
14 1*/

#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

pair<int, int> minMax(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = INT_MIN;
        p.second = INT_MAX;
        return p;
    }
    pair<int, int> left = minMax(root->left);
    pair<int, int> right = minMax(root->right);

    pair<int, int> ans;
    ans.first = max(max(left.first, right.first), root->data);
    ans.second = min(min(left.second, right.second), root->data);

    return ans;
}