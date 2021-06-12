/*Problem Statement: kReverse
Problem Level: HARD
Problem Description:
Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
'k' is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of 'k,' then left-out nodes, in the end, should be reversed as well.
Example :
Given this linked list: 1 -> 2 -> 3 -> 4 -> 5

For k = 2, you should return: 2 -> 1 -> 4 -> 3 -> 5

For k = 3, you should return: 3 -> 2 -> 1 -> 4 -> 5

Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains a single integer depicting the value of 'k'.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= k <= M

Time Limit:  1sec

Sample Input 1 :
1
1 2 3 4 5 6 7 8 9 10 -1
4

Sample Output 1 :
4 3 2 1 8 7 6 5 10 9

Sample Input 2 :
2
1 2 3 4 5 -1
0
10 20 30 40 -1
4

Sample Output 2 :
1 2 3 4 5 
40 30 20 10*/

class Solution
{
    public:
    int length(struct node* head){
        struct node* temp = head;
        int l = 0;
        while(temp != NULL){
            temp = temp->next;
            l++;
        }
        return l;
    }
    pair<struct node*,struct node*> reverseLL(struct node* head, int k){
        if(k==0 || k==1){
            pair<struct node*,struct node*> p;
            p.first = head;
            p.second = head;
            return p;
        }
        pair<struct node*,struct node*> p = reverseLL(head->next,k-1);
        p.second->next = head;
        p.second  = p.second->next;
        return p;
    }
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        int l = length(head);
        if(l ==0){
            return NULL;
        }
        if(l >= k){
            struct node* temp = head;
            struct node* prev = NULL;
            for(int i=0;i<k;i++){
                prev = NULL;
                temp = temp->next;
            }
            pair<struct node*,struct node*> p = reverseLL(head,k);
            node* small = reverse(temp,k);
            p.second->next = small;
            return p.first;
            
        }else{
             pair<struct node*,struct node*> p = reverseLL(head,l);
             p.second->next = NULL;
             return p.first;
        }
    }
};