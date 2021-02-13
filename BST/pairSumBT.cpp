/*Pair sum BInary Tree
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Assume binary tree contains all unique elements.
Note : In a pair, print the smaller element first. Order of different pair doesn't matter.
Input format :
Line 1 : Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 2 : Integer S
Output Format :
Each pair in different line (pair elements separated by space)
Constraints :
1 <= N <= 1000
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15
Sample Output 1:
5 10
6 9
*/

// repeat

#include <bits/stdc++.h>
using namespace std;
#include "binaryTree.h"

vector<int> *printPair(BinaryTreeNode<int> *root, int s)
{
    if (root == NULL)
    {
        return NULL;
    }
    int x = root->data;

    vector<int> *v;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    v->push_back(root->data);

    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        q.push(root->left);
        q.push(root->right);
        v->push_back(root->left->data);
        v->push_back(root->right->data);
    }
    return v;
}
void print(BinaryTreeNode<int> *root, int s)
{
    vector<int> *v = printPair(root, s);
    sort(v->begin(), v->end());
    int i = 0;
    int j = v->size() - 1;
    while (i <= j)
    {
        if ((v->at(i) + v->at(j)) < s)
        {
            j--;
        }
        else if ((v->at(i) + v->at(j)) > s)
        {
            i++;
        }
        else if ((v->at(i) + v->at(j)) == s)
        {
            cout << v->at(i) << " " << v->at(j) << endl;
            j--;
            i++;
        }
    }
}