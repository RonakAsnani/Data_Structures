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

int main()
{
    Node *head = takeinput();
    head = sor(head);
    print(head);
    return 0;
}