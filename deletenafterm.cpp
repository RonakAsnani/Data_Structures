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

Node *dele(Node *head, int m, int n)
{
    if (m == 0)
    {
        return NULL;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        int i = 1;
        while (temp != 0 && i < m)
        {
            i++;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            return head;
        }
        i = 0;
        Node *dem = temp->next;
        while (dem != NULL && i <= n)
        {
            i++;
            Node *x = dem;
            dem = dem->next;
            delete[] x;
        }
        temp->next = dem;
        temp = dem;
    }
    return head;
}

int main()
{
    Node *head = takeinput();
    int n, m;
    cin >> m >> n;
    head = dele(head, m, n);
    print(head);
    return 0;
}