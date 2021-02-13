/*Path Sum Root to Leaf
Given a binary tree and a number k, print out all root to leaf paths where the sum of all nodes value is same as the given number k.
Input format :

Line 1 : Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Line 2 : k

Output format : Print each path in new line, elements separated by space

Sample Input 1 :
5 6 7 2 3 -1 1 -1 -1 -1 9 -1 -1 -1 -1
13
Sample Output 1 :
5 6 2
5 7 1*/

// repeat

#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

vector<int> *sum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    //int ans = root->data;
    vector<int> *v1 = sum(root->left);
    vector<int> *v2 = sum(root->right);

    vector<int> *v = new vector<int>();
    int k = 0;
    for (int i = 0; i < (v1->size()); i++)
    {

        v->at(k) = root->data + v1->at(i);
        k++;
    }
    for (int i = 0; i < (v2->size()); i++)
    {
        v->at(k) = root->data + v2->at(i);
        k++;
    }
}

void printSumPath(BinaryTreeNode<int> *root, int s, vector<int> *v)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == s && root->left == NULL && root->right == NULL)
    {
        //v->push_back(root->data);
        for (int i = 0; i < v->size(); i++)
        {
            cout << v->at(i) << " ";
        }
        cout << root->data << endl;
        return;
    }

    v->push_back(root->data);

    printSumPath(root->left, s - root->data, v);
    printSumPath(root->right, s - root->data, v);
}