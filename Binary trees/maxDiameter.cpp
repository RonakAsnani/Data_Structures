#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

// class Pair{
//     int height;
//     int diameter;
// };

// int height(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }
//     return 1 + max(height(root->left), height(root->right));
// }

// int diameter(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }
//     int option1 = height(root->left) + height(root->right);
//     int option2 = diameter(root->left);
//     int option3 = diameter(root->right);

//     int ans = max(option1, option2, option3);
//     return ans;
// }

pair<int, int> heidia(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftans = heidia(root->left);
    pair<int, int> right = heidia(root->right);

    int ld = leftans.second;
    int lh = leftans.first;
    int rd = right.second;
    int rh = right.first;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, ld, rd);

    pair<int, int> p1;
    p1.first = height;
    p1.second = height;

    return p1;
}