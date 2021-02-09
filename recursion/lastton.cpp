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

int len(Node *head)
{
    int c = 0;
    while (head != NULL)
    {
        head = head->next;
        c++;
    }
    return c;
}

Node *append(Node *head, int n)
{
    Node *temp = head;
    Node *dem = head;
    int x = len(head) - n;
    while (temp != NULL && x > 1)
    {
        temp = temp->next;
        x--;
    }
    while (dem->next != NULL)
    {
        dem = dem->next;
    }
    bool a = true;
    while (a)
    {
        dem->next = head;
        head = temp->next;
        a = false;
    }

    return head;
}

int main()
{
    Node *head = takeinput();
    head = append(head, 3);
    print(head);
    return 0;
}