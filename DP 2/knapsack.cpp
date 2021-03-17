/*Code : Knapsack
A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is value vi. What is the maximum value V, that thief can take ?
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 20
1<= wi <= 100
1 <= vi <= 100
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13*/

#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int maxv, int *w, int *v)
{
    if (n == 0 || maxv == 0)
    {
        return 0;
    }
    if (w[0] > maxv)
    {
        return knapsack(n - 1, maxv, w + 1, v + 1);
    }

    int x = knapsack(n - 1, maxv - w[0], w + 1, v + 1) + v[0];
    int y = knapsack(n - 1, maxv, w + 1, v + 1);

    return max(x, y);
}

// memoization

int main()
{
    int n;
    cin >> n;
    int *w = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    int *v = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int maxw;
    cin >> maxw;
    cout << knapsack(n, maxw, w, v);
    return 0;
}