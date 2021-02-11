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
void printzigzag(BinaryTreeNode<int> *root)
{
    int level = 1;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    cout << root->data << endl;
    while (!q.empty())
    {
        level++;
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        if (front->left != NULL && front->right != NULL)
        {
            if (level % 2 == 0)
            {
                cout << front->right->data << " " << front->left->data << endl;
            }
            if (level % 2 != 0)
            {
                cout << front->left->data << " " << front->right->data << endl;
            }
            q.push(front->left);
            q.push(front->right);
        }
        if (front->left == NULL && front->right != NULL)
        {
            cout << front->right->data;
            //q.push(front->left);
            q.push(front->right);
        }
        if (front->left != NULL && front->right == NULL)
        {
            cout << front->left->data;
            //q.push(front->left);
            q.push(front->left);
        }
    }
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{

    BinaryTreeNode<int> *root = takeInputLevelWise();

    printzigzag(root);
}