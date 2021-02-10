/*  
Contains x
Given a generic tree and an integer x, check if x is present in the given tree or not. Return true if x is present, return false otherwise.
Input format :
Line 1 : Integer x
Line 2 : Elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Output format :
true or false
Sample Input 1 :
40
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
true
Sample Input 2 :
4
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 2:
false*/

#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "enter number of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "enter " << i << " th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

bool containX(TreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    bool ans = false;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = containX(root->children[i], x);
        if (ans == true)
        {
            break;
        }
    }
    return ans;
}

bool containX_2(TreeNode<int> *root, int x)
{
    queue<TreeNode<int> *> s;
    s.push(root);

    while (!s.empty())
    {
        if (root->data == x)
        {
            return true;
        }
        TreeNode<int> *front = s.front();
        s.pop();
        for (int i = 0; i < root->children.size(); i++)
        {
            s.push(root->children[i]);
        }
    }
    return false;
}

int main()
{
    int x;
    cin >> x;
    TreeNode<int> *root = takeInputLevelWise();
    cout << containX(root, x);
}