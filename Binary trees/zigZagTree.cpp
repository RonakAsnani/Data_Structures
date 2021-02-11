/*ZigZag Tree
Given a binary tree, print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5
10 6
2 3
9*/

#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

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