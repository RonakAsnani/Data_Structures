/*  
Eliminate duplicates from LL
Given a sorted linked list (elements are sorted in ascending order). Eliminate duplicates from the given LL, such that output LL contains only unique elements.
You don't need to print the elements, just remove duplicates and return the head of updated LL.
Input format : Linked list elements (separated by space and terminated by -1)

Sample Input 1 :
1 2 3 3 3 4 4 5 5 5 7 -1
Sample Output 1 :
1 2 3 4 5 7*/

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

Node *eliminate(Node *head)
{
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        //Node*temp = head->next;
        if (temp->data == (temp->next)->data)
        {
            Node *dem = temp->next;
            temp->next = (temp->next)->next;
            delete[] dem;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}
