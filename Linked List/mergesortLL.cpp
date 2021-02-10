/*Code: Merge Sort
Sort a given linked list using Merge Sort.
You don't need to print the elements, just sort the elements and return the head of updated LL.
Input format :
Linked list elements (separated by space and terminated by -1)
Output format :
Updated LL elements (separated by space)
Constraints :
1 <= Length of LL <= 1000
Sample Input 1 :
1 4 5 2 -1
Sample Output 1 :
1 2 4 5
*/

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

Node *mergesort(Node *h1, Node *h2)
{
    Node *fh = NULL;
    Node *ft = NULL;

    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data < h2->data)
        {
            if (fh == NULL)
            {
                fh = h1;
                ft = h1;
            }
            else
            {
                ft->next = h1;
                ft = h1;
            }
            h1 = h1->next;
        }
        if (h1->data > h2->data)
        {
            if (fh == NULL)
            {
                fh = h2;
                ft = h2;
            }
            else
            {
                ft->next = h2;
                ft = h2;
            }
            h2 = h2->next;
        }
    }

    if (h1 != NULL && h2 == NULL)
    {
        ft->next = h1;
    }
    if (h2 != NULL && h1 == NULL)
    {
        ft->next = h2;
    }

    return fh;
}
int main()
{
    Node *l1 = takeinput();
    Node *l2 = takeinput();

    Node *head = mergeso(l1, l2);
    print(head);
    return 0;
}