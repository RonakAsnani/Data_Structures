/*Code: BST Class
Implement the BST class which includes following functions -
1. search
Given an element, find if that is present in BSt or not. Return true or false.
2. insert -
Given an element, insert that element in the BST at the correct position. Assume unique elements will be given.
3. delete -
Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from the right sub-tree.
4. printTree (recursive) -
Print the BST in ithe following format -
For printing a node with data N, you need to follow the exact format -
N:L:x,R:y
 
where, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.
There is no space in between.
You need to print all nodes in the recursive format in different lines.
Note : main function is given for your reference which we are using internally to test the class.*/

#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

class BST
{
private:
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

private:
    BinaryTreeNode<int> *ins(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            BinaryTreeNode<int> *ne = new BinaryTreeNode<int>(data);

            return ne;
            ;
        }

        if (data < root->data)
        {
            root->left = ins(data, root->left);
        }
        else if (data > root->data)
        {
            root->right = ins(data, root->right);
        }
        return root;
    }

public:
    void insert(int data)
    {
        root = ins(data, root);
    }

private:
    BinaryTreeNode<int> *maxi(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        return maxi(root->right);
    }
    BinaryTreeNode<int> *del(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->data > data)
        {
            root->left = del(data, root->left);
            return root;
        }
        else if (root->data < data)
        {
            root->right = del(data, root->right);
            return root;
        }
        else if (root->data = data)
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete (root);
                return NULL;
            }
            else if (root->left != NULL && root->right == NULL)
            {
                BinaryTreeNode<int> *temp = root->left;
                root->left = NULL;
                delete (root);
                return temp;
            }
            else if (root->left == NULL && root->right != NULL)
            {
                BinaryTreeNode<int> *temp = root->right;
                root->right = NULL;
                delete (root);
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *temp = maxi(root->left);
                root->data = temp->data;
                root->left = del(temp->data, root->left);
                return root;
            }
        }
    }

public:
    void deleteData(int data)
    {
        root = del(data, root);
    }

private:
    bool hasDat(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->data = data)
        {
            return true;
        }
        else if (data < root->data)
        {
            return hasDat(data, root->left);
        }
        else
        {
            return hasDat(data, root->right);
        }
    }

public:
    bool hasData(int data)
    {
        return hasDat(data, root);
    }
};