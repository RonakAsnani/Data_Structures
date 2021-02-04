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
int find(Node *head, int n)
{
    int count = -1;
    while (head != NULL)
    {
        if (head->data == n)
        {
            count++;
            return count;
        }
        else
        {
            head = head->next;
            count++;
        }
    }
    return -1;
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

Node *del(Node *head, int i)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (i == 0)
    {
        Node *temp = head;
        head = head->next;
        delete[] temp;
        return head;
    }
    if (i == 1)
    {
        Node *temp = head->next;
        head->next = temp->next;
        delete[] temp;
        return head;
    }

    Node *curr = del(head->next, i - 1);
    return head;
}

int main()
{
    int n;
    Node *head = takeinput();

    cin >> n;
    // head = del(head, n);
    // print(head);
    cout << find(head, n);
    return 0;
}