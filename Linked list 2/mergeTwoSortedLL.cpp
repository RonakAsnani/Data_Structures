/*Problem Statement: Merge Two Sorted Linked Lists
Problem Level: MEDIUM
Problem Description:
You have been given two sorted(in ascending order) singly linked lists of integers.
Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order) and return the new head to the list.
Note :
Try solving this in O(1) auxiliary space.

No need to print the list, it has already been taken care.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the first sorted singly linked list separated by a single space.

The second line of the input contains the elements of the second sorted singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output :
For each test case/query, print the resulting sorted singly linked list, separated by a single space.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t = 10^2
0 <= N <= 10 ^ 4
0 <= M <= 10 ^ 4
Where N and M denote the sizes of the singly linked lists.

Time Limit: 1sec

Sample Input 1 :
1
2 5 8 12 -1
3 6 9 -1

Sample Output 1 :
2 3 5 6 8 9 12

Sample Input 2 :
2
2 5 8 12 -1
3 6 9 -1
10 40 60 60 80 -1
10 20 30 40 50 60 90 100 -1

Sample Output 2 :
2 3 5 6 8 9 12 
10 10 20 30 40 40 50 60 60 60 80 90 100*/

#include<iostream>
using namespace std;
#include "Node.cpp"

Node* takeInput()
{
    int data;
    cin>>data;
    Node* head = NULL;
    Node* prev =NULL;
    while(data != -1){
        Node* n = new Node(data);
        if(head == NULL){
            head = n;
            prev =n;
        }
        prev->next = n;
        prev = prev->next;
        

        cin>>data;
    }
    return head;
}
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp  = temp->next;
    }
}
Node* merge(Node* h1,Node* h2){
    Node* head =NULL;
    Node* curr ;
    while(h1 != NULL && h2 != NULL){
        if(h1->data > h2->data){
            if(head == NULL){
                head = h2;
                curr =h2;
                h2 = h2->next;
                curr->next = NULL;
            }else{
            curr->next = h2;
            curr = curr->next;
            curr->next = NULL;
            h2 = h2->next;
            }
        }else{
            if(head == NULL){
                head = h1;
                curr =h1;
                h1 = h1->next;
                curr->next = NULL;
            }else{
            curr->next = h1;
            curr = curr->next;
            curr->next = NULL;
            h1 = h1->next;
            }
        }
    }
    while(h1 != NULL){
        if(head == NULL){
            head = h1;
            
        }
        curr = h1;
    }
    while(h2 != NULL){
        if(head == NULL){
            head = h2;
            
        }
        curr = h2;
    }
    return head;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        Node* h1 = takeInput();
        Node* h2 = takeInput();
        Node* head = merge(h1,h2);
        print(head);
    }
    return 0;
}