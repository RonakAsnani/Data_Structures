/*Code : Has Path
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
true or false
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false*/
#include <bits/stdc++.h>
using namespace std;

bool hasPath(int **edges, int n, int st, int en, bool *visited)
{
    if (st == en)
    {
        return true;
    }
    visited[st] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == en && edges[st][i] == 1 && !visited[i])
        {
            visited[i] = true;
            return true;
        }
        else if (edges[st][i] == 1 && !visited[i])
        {
            return hasPath(edges, n, i, en, visited);
        }
    }
    return false;
}
bool path(int **edges, int n, int st, int en)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    return hasPath(edges, n, st, en, visited);
}

int main()
{
    int n;
    int e;
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int st, en;
    cin >> st >> en;
    cout << path(edges, n, st, en);
    return 0;
}