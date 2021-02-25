/*  
Code : Dijkstra's Algorithm
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
In different lines, ith vertex number and its distance from source (separated by space)
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
*/

#include <bits/stdc++.h>
using namespace std;

int findMin(int *weight, bool *visted, int n)
{
    int m = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visted[i] && (m == -1 || weight[m] > weight[i]))
        {
            m = i;
        }
    }
    return m;
}

void dijkstra(int **edges, int n)
{
    bool *visited = new bool[n];
    //int *weight = new int[n];
    int *dist = new int[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[0] = 0;
    //weight[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int m = findMin(dist, visited, n);
        visited[m] = true;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && edges[i][j] != 0)
            {
                int d = dist[m] + edges[m][j];
                if (dist[j] > d)
                {
                    dist[j] = d;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << dist[i] << endl;
    }
}

int main()
{
    int n, e;
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
        int s, d, w;
        cin >> s >> d >> w;
        edges[s][d] = w;
        edges[d][s] = w;
    }
    cout << endl;

    dijkstra(edges, n);

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}