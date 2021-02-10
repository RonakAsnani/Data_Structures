/*
Delete node
Given a linked list and a position i, delete the node of ith position from Linked List iteratively.
If position i is greater than length of LL, then you should return the same LL without any change.
Indexing starts from 0. You don't need to print the elements, just delete the node and return the head of updated LL.
Input format :
Line 1 : Linked list elements (separated by space and terminated by -1)
Line 2 : Integer i (position)
Output format :
Updated LL elements (separated by space)
Sample Input 1 :
3 4 5 2 6 1 9 -1
3
Sample Output 1 :
3 4 5 6 1 9
Sample Input 2 :
3 4 5 2 6 1 9 -1
0
Sample Output 2 :
4 5 2 6 1 9*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *deleteNode(Node *head, int i)
{
    int c = 0;
    Node *temp = head;
    if (i == 0)
    {

        head = temp->next;
        delete[] temp;
    }
    while (temp != NULL && c < i - 1)
    {
        temp = temp->next;
        c++;
    }
    if (temp != NULL)
    {
        Node *dem = temp->next;
        temp->next = (dem)->next;
        delete[] dem;
    }
    return head;
}
