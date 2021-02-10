/*Print ith node
Given a linked list and a position i, print the node at ith position.
If position i is greater than length of LL, then don't print anything.
Indexing starts from 0.
Input format :
Line 1 : Linked list elements (separated by space and terminated by -1)
Line 2 : Integer i (position)
Output format :
Element at ith position
Sample Input 1 :
3 4 5 2 6 1 9 -1
3
Sample Output 1 :
2
Sample Input 2 :
3 4 5 2 6 1 9 -1
0
Sample Output 2 :
3
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

int main()
{
    Node *head = takeinput();
    int n;
    cin >> n;
    Node *temp = head;
    for (int i = 0; i < n; i++)
    {
        temp = temp->next;
    }
    cout << temp->data;
    return 0;
}