/*
Code: Merge Two Sorted LL
Given two linked lists sorted in increasing order. Merge them in such a way that the result list is also sorted (in increasing order).
Try solving with O(1) auxiliary space (in-place). You just need to return the head of new linked list, don't print the elements.
Input format :
Line 1 : Linked list 1 elements of length n (separated by space and terminated by -1)
Line 2 : Linked list 2 elements of length m (separated by space and terminated by -1)
Output format :
Merged list elements (separated by space)
Constraints :
1 <= n, m <= 10^4
Sample Input :
 2 5 8 12 -1
 3 6 9 -1
Sample Output :
 2 3 5 6 8 9 12 */

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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = tail->next;
        }

        cin >> data;
    }
    return head;
}

Node *mergeso(Node *h1, Node *h2)
{
    if (h1 == NULL)
    {
        return h2;
    }
    if (h2 == NULL)
    {
        return h1;
    }

    if (h1->data > h2->data)
    {
        Node *small = mergeso(h1, h2->next);
        h2->next = small;
        return h2;
    }
    if (h1->data < h2->data)
    {
        Node *small = mergeso(h1->next, h2);
        h1->next = small;
        return h1;
    }
    return NULL;
}

Node *midLL(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *mergesorting(Node *h1)
{
    if (h1 == NULL || h1->next == NULL)
    {
        return h1;
    }
    Node *mid = midLL(h1);
    Node *midf = mid->next;
    mid->next = NULL;
    Node *start = mergesorting(h1);
    Node *end = mergesorting(midf);

    return mergeso(start, end);
}

int main()
{
    Node *h1 = takeinput();

    h1 = mergesorting(h1);
    print(h1);
    return 0;
}