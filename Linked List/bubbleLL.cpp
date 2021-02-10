/*Bubble Sort (Iterative) LinkedList
Sort a given linked list using Bubble Sort (iteratively). While sorting, you need to swap the entire nodes, not just the data.
You don't need to print the elements, just sort the elements and return the head of updated LL.
Input format : Linked list elements (separated by space and terminated by -1)`

Sample Input 1 :
1 4 5 2 -1
Sample Output 1 :
1 2 4 5*/

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

Node *sor(Node *head)
{
    for (int i = 0; i < len(head); i++)
    {
        Node *prev = NULL, *curr = head;
        while (curr->next != NULL)
        {
            if (curr->data > curr->next->data)
            {
                if (prev == NULL)
                {

                    head = curr->next;
                    curr->next = head->next;
                    head->next = curr;
                    prev = head;
                }
                else
                {
                    Node *temp = curr->next->next;
                    curr->next->next = curr;
                    prev->next = curr->next;
                    curr->next = temp;
                    //temp = curr;
                    prev = prev->next;
                }
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }
    return head;
}
