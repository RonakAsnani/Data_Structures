#include <bits/stdc++.h>
using namespace std;

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