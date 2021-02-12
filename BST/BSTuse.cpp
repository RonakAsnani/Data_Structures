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
        left.second->next = link;

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
        left.second->next = link;
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

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data: " << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    queue<BinaryTreeNode<int> *> q;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChild;
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChild);
            front->left = child;
            q.push(child);
        }

        cout << "Enter right child of " << front->data << endl;
        int rightChild;
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChild);
            front->right = child;
            q.push(child);
        }
    }
    return root;
}

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
BinaryTreeNode<int> *tree(int *arr, int n)
{
    int st = 0;
    int en = n - 1;
    return cons(arr, st, en);
}
void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        cout << front->data << ": ";
        if (front->left != NULL)
        {
            cout << "L" << front->left->data;
            q.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << "R" << front->right->data;
            q.push(front->right);
        }
        cout << endl;
    }
}

int main()
{

    BinaryTreeNode<int> *root = takeInputLevelWise();
    pair<Node<int> *, Node<int> *> p = LL(root);
    Node<int> *temp = p.first;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    //delete (root);
}