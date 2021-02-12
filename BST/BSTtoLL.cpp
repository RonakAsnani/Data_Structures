/*Code: BST to Sorted LL
Given a BST, convert it into a sorted linked list. Return the head of LL.
Sample Input :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output :
2 5 6 7 8 10*/

// not running

#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

template <typename T>
class Node
{
public:
    T data;
    Node *next;
};
pair<Node<int> *, Node<int> *> LL(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<Node<int> *, Node<int> *> p;
        p.first = NULL;
        p.second = NULL;
        return p;
    }
    pair<Node<int> *, Node<int> *> ans;
    if (root->left != NULL && root->right != NULL)
    {
        pair<Node<int> *, Node<int> *> left = LL(root->left);
        pair<Node<int> *, Node<int> *> right = LL(root->right);
        Node<int> *link;
        link->data = root->data;
        link->next = right.first;
        left.second = link;

        ans.first = left.first;
        ans.second = right.second;
    }
    if (root->left == NULL && root->right != NULL)
    {
        pair<Node<int> *, Node<int> *> right = LL(root->right);
        Node<int> *link;
        link->data = root->data;
        link->next = right.first;

        ans.first = link;
        ans.second = right.second;
    }
    if (root->left != NULL && root->right == NULL)
    {
        pair<Node<int> *, Node<int> *> left = LL(root->left);
        Node<int> *link;
        link->data = root->data;
        left.second = link;
        ans.first = left.first;
        ans.second = link;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.first = NULL;
        ans.second = NULL;
    }

    return ans;
}
