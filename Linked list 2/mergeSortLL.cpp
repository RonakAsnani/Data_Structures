/*Problem Statement: MergeSort  Linked List
Problem Level: MEDIUM
Problem Description:
Given a singly linked list of integers, sort it using 'Merge Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec

Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1

Sample Output 1 :
 3 4 5 6 7 8 9 10

Sample Output 2 :
2
-1
10 -5 9 90 5 67 1 89 -1

Sample Output 2 :
-5 1 5 9 10 67 89 90
*/

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
        }else{
        prev->next = n;
        prev = prev->next;
        }

        cin>>data;
    }
    return head;
}
Node* merge(Node* h1,Node* h2){
    Node* head;
    Node* tail;
    // if(h1 == NULL && h2 == NULL){
    //     return head;
    // }else if(h1 == NULL){
    //     return h2;
    // }else if(h2 == NULL ){
    //     return h1;
    // }
    if(h1->data < h2->data){
        head = h1;
        tail = h1;
        h1 = h1->next;
    }else {
        head = h2;
        tail = h2;
        h2 = h2->next;
    }
    while(h1 != NULL && h2 != NULL){
        if(h1->data < h2->data){
            tail->next = h1;
            h1 = h1->next;
            tail = tail->next;
            
        }else{
            tail->next = h2;
            h2 = h2->next;
            tail = tail->next;
            
        }
        
    }
    if(h1 != NULL){
        tail->next = h1;

    }
    if(h2 != NULL){
        tail->next = h2;
    }
    return head;

}
Node* mid(Node* head){
   Node* slow = head;
    Node* fast = head;
    while(fast->next !=NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp  = temp->next;
    }
}
Node* mergesort(Node* head,Node* tail){
    if(head == tail){
        return head;
    }
    Node* m = mid(head);
    Node* x = m->next;
    m->next =NULL;
    Node* h1 = mergesort(head,m);
    Node* h2 = mergesort(x,tail);
    return merge(h1,h2);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        Node* head = takeInput();
        if(head == NULL){
            continue;
        }
        Node* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        head = mergesort(head,tail);
        print(head);
    }
    return 0;
}