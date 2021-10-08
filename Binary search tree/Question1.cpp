/* -----Problem question-----
Alice and Bob are playing a game. Alice gave Bob
four types of characters 'a', 'b', 'c' and 'd' each
having a count of A, B, C, and D respectively.
Alice allows Bob to do the following operation as
many times he wants:
choose 'a', 'b' and 'c' and change them to the
character 'd'. More formally in one operation we
need to decrease one occurence of each 'a','b','c!
and convert them to 'd' hence increasing occurence
of 'd' by 3.
Bob has to arrange the characters in such a way
that after some number of operations the resulting
arrangement is a palindrome.
If Bob fails to do so Alice wins the game otherwise
Bob wins.
Input Format
The first line contains one integer T, denoting the
number of test cases.
For each of the next T lines, each line contains four
Integers A, B, C, and D.
Constraints
1 sTs 300,
OS A, B, C, D S 1019
Output Format
For each test case print 'Bob' if Bob wins otherwise
print 'Alice' after a certain number of operations
possibly zero ).
Sample Input
3
5 4 3 2
9 8 14 1
5 741
Sample Output
Alice
Alice
Bob
Time Limit: 1
Memory Limit: 256
Source Limit:

*/

// here is solution 

#include <iostream>
using namespace std;
 
int main()
{
   long long int t;
   cin>>t;
   while(t--)
   {
       long long int a,b,c,d,test=0,tmp=0;
       cin>>a>>b>>c>>d;
     
       if(a%2==1)
        {
            tmp+=1;
        }
        if(b%2==1)
        {
            tmp+=1;
        }
        if(c%2==1)
        {
            tmp+=1;
        }if(d%2==0&&tmp==2)
        cout<<"Alice"<<"\n";
        else if (d%2==1&&tmp==1)
        cout<<"Alice"<<"\n";
        else if((a==0 || b==0 || c==0) && (tmp=2))
        cout<<"Alice"<<"\n";
        else
        cout<<"Bob"<<"\n";
      
   }
 
    return 0;
}
