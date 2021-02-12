/*Code: Construct BST from a Sorted Array
Given a sorted integer array A of size n which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.Note : If array size is even, take first mid as root.
Sample Input :
7
1 2 3 4 5 6 7
Sample Output :
4 2 1 3 6 5 7
*/

#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

BinaryTreeNode<int> *cons(int *arr, int si, int ei)
{
    if (si > ei)
    {
        return NULL;
    }
    int mid = (si + ei) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[mid]);

    root->left = cons(arr, si, mid - 1);
    root->right = cons(arr, mid + 1, ei);

    return root;
}
