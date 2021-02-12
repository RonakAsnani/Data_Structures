/*Check if a Binary Tree is BST
Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree) or not. If yes, return true, return false otherwise. Duplicate elements should be in the right subtree.
Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1
Sample Output 1 :
true
Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
Sample Output 2 :
false*/

#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

class isBSTreturn
{
public:
    bool isBST;
    int mi;
    int ma;
};

int ma(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(ma(root->left), ma(root->right)));
}
int mi(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    return min(root->data, min(mi(root->left), mi(root->right)));
}
// O(n^2)
bool ifBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }

    int leftMax = ma(root->left);
    int rightmin = mi(root->right);

    bool out = (root->data > leftMax) && (root->data < rightmin) && ifBST(root->left) && ifBST(root->right);

    return out;
}
// O(n)
isBSTreturn isBST2(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        isBSTreturn out;
        out.isBST = true;
        out.mi = INT_MAX;
        out.ma = INT_MIN;
        return out;
    }

    isBSTreturn leftout = isBST2(root->left);
    isBSTreturn rightout = isBST2(root->right);

    int minimum = min(root->data, min(leftout.mi, rightout.mi));
    int maximum = max(root->data, max(leftout.ma, rightout.ma));

    bool ans = (root->data > leftout.ma) && (root->data <= rightout.mi) && leftout.isBST && rightout.isBST;
    isBSTreturn output;
    output.isBST = ans;
    output.ma = maximum;
    output.mi = minimum;
}

// O(n)

bool isBST3(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data < min || root->data > max)
    {
        return false;
    }
    bool isLeft = isBST3(root->left, min, root->data - 1);
    bool isRight = isBST3(root->right, root->data, max);

    return isLeft && isRight;
}