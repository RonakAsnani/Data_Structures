/*  
Insert node (recursive)
Given a linked list, an integer n and a position i, Insert that node n into Linked List at ith position recursively.
If position i is greater than length of LL, then you should return the same LL without any change. And if position i is equal to length of input LL, insert the node at last position.
Indexing starts from 0. You don't need to print the elements, just insert and return the head of updated LL.
Input format :
Line 1 : Linked list elements (separated by space and terminated by -1)
Line 2 : Integer i (position)
Line 3 : Integer n (Node to be inserted)
Output format :
Updated LL elements (separated by space)
Sample Input 1 :
3 4 5 2 6 1 9 -1
3
100
Sample Output 1 :
3 4 5 100 2 6 1 9
Sample Input 2 :
3 4 5 2 6 1 9 -1
0
20
Sample Output 2 :
20 3 4 5 2 6 1 9*/

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

Node *insert(Node *head, int i, int data)
{
    //Node *temp = head;
    if (head == NULL)
    {
        return NULL;
    }
    if (i == 0)
    {
        Node *ne = new Node(data);
        ne->next = head;
        return ne;
    }
    if (i == 1)
    {
        Node *ne = new Node(data);
        ne->next = head->next;
        head->next = ne;
        return ne;
    }
    Node *curr = insert(head->next, i - 1, data);

    return head;
}
