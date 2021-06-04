/*Problem Statement: Even after Odd LinkedList
Problem Level: MEDIUM
Problem Description:
For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. The relative order of the odd and even terms should remain unchanged.
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format:
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format:
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec

Sample Input 1 :
1
1 4 5 2 -1

Sample Output 1 :
1 5 4 2

Sample Input 2 :
2
1 11 3 6 8 0 9 -1
10 20 30 40 -1

Sample Output 2 :
1 11 3 9 6 8 0
10 20 30 40*/
 
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
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp  = temp->next;
    }
}
 
 int main(){
    int t;
    cin>>t;
    while(t--){
        Node*head = takeInput();
        Node* even = NULL;
        Node* odd = NULL;
        Node* es = NULL;
        Node* os = NULL;
        //cout<<head->data<<endl;
        while(head != NULL){
            if(head->data%2 == 0){
                if(even == NULL){
                    even = head;
                    es = head;
                }else{
                    even->next = head;
                    even = even->next;
                }

            }else{
                if(odd == NULL){
                    odd = head;
                    os = head;
                }else{
                    odd->next = head;
                    odd = odd->next;
                }
 
            }

        head = head->next;
        }
        
        
        if(os == NULL){
            print(es);
        }else{
            odd->next =es;
        even->next = NULL;
        print(os);
        }
    } 
    return 0;
 }