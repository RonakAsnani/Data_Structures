/*Level wise linkedList
Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains the head of each level linked list.
Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5 
6 10 
2 3 
9
*/

#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

vector<Node<int> *> levelWiseLL(BinaryTreeNode<int> *root)
{
    vector<Node<int> *> v;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    Node<int> *L1 = new Node<int>(root->data);
    v.push_back(L1);

    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        if (front->left != NULL && front->right != NULL)
        {
            Node<int> *L2 = new Node<int>(front->left->data);
            Node<int> *L3 = new Node<int>(front->right->data);
            L2->next = L3;
            v.push_back(L2);
            q.push(front->left);
            q.push(front->right);
        }
        if (front->left == NULL && front->right != NULL)
        {
            Node<int> *L3 = new Node<int>(front->right->data);
            L3->next = NULL;
            v.push_back(L3);
            q.push(front->right);
        }
        if (front->left != NULL && front->right == NULL)
        {
            Node<int> *L3 = new Node<int>(front->left->data);
            L3->next = NULL;
            v.push_back(L3);
            q.push(front->left);
        }
    }
    return v;
}
