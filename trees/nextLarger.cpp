/*Next larger
Given a generic tree and an integer n. Find and return the node with next larger element in the Tree i.e. find a node with value just greater than n.
Return NULL if no node is present with the value greater than n.
Input Format :
Line 1 : Integer n
Line 2 : Elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Output Format :
Node with value just greater than n.
Sample Input 1 :
18
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
20
Sample Input 2 :
21
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 2:
30*/

#include <bits/stdc++.h>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int> *nextLarger(TreeNode<int> *root, int n)
{
    queue<TreeNode<int> *> s;
    s.push(root);
    TreeNode<int> *m = NULL;

    while (!s.empty())
    {
        TreeNode<int> *front = s.front();
        if (m == NULL && front->data > n)
        {
            m = front;
        }
        if (m != NULL && front->data > n && front->data < m->data)
        {
            m = front;
        }

        s.pop();
        for (int i = 0; i < front->children.size(); i++)
        {
            s.push(front->children[i]);
        }
    }
    return m;
}
