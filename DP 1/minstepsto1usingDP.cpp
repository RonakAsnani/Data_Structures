/*
Code : Min Steps to 1 using DP
Given a positive integer n, find the minimum number of steps s, that takes n to 1. You can perform any one of the following 3 steps.
1.) Subtract 1 from it. (n= n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n%2==0, then n= n/2 ) ,
3.) If its divisible by 3, divide by 3. (if n%3 == 0, then n = n / 3 ). 
The time complexity of your code should be O(n).
Input format :
Line 1 : A single integer i.e. n
Output format :
Line 1 : Single integer i.e number of steps
Constraints :
1 <= n <= 10^5
Sample Input 1 :
4
Sample Output 1 :
2 
Sample Output 1 Explanation :
For n = 4
Step 1 : n = 4/2 = 2
Step 2 : n = 2/2 = 1
Sample Input 2 :
7
Sample Output 2 :
3
Sample Output 2 Explanation :
For n = 7
Step 1 : n = 7 ­ - 1 = 6
Step 2 : n = 6 / 3 = 2
Step 3 : n = 2 / 2 = 1*/
