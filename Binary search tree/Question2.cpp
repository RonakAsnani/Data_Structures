/* ----Problem----
Crite your code or upload youth
1 include <iostream
using ratespace std;
Alice is obsessed with circles and needs
your help to get the largest special circle
given an integer N. Special circle is a
circle with integer radius if it is removed
from a circle of radius N then circle left
has area less than fourth of the area of
the circle of radius N.
INPUT
5
6
7
0 

OUTPUT
20
21
22
return 0
For each test case print the radius of the
largest possible special circle.
CONSTRAINTS
1sts 10
1 ss 1012
provide custom input
Sample
Sample Output
COMPLEA TEST SUBMIT
2
11
17
Time Limit1
Memory Limit: 256
Source Limit*/


// code solution 

#include <iostream>
using namespace std;
 
int main()
{
    long long int t,N,tmp=0;
    cin>>t;
    while(t--)
    {
            cin>>N;
     
         if(N%2==0)
         {
             tmp=(N/2)-1;
         }
         else
         {
             tmp=N/2;
         }
         cout<<tmp<<"\n";
 
    }
 
    return 0;
}