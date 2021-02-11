/*Level Order Traversal
Given a binary tree, print the level order traversal. Make sure each level start in new line.
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