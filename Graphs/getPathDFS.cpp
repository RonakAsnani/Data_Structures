/*Code : Get Path - DFS
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space)
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
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :*/

#include <bits/stdc++.h>
using namespace std;

vector<int> getPath(int **edges, int n, int st, int en, vector<int> v, bool *visited)
{
    // bool *visited = new bool[n];
    // for (int i = 0; i < n; i++)
    // {
    //     visited[i] = 0;
    // }
    if (st == en)
    {
        return v;
    }

    vector<int> x;
    v.push_back(st);
    for (int i = 0; i < n; i++)
    {
        if (i == en && visited[i] == 1 && !visited[i])
        {
            v.push_back(i);
            visited[i] = true;
            return v;
        }
        else if (visited[i] == 1 && !visited[i])
        {
            return getPath(edges, n, i, en, v, visited);
        }
    }
    return x;
}

vector<int> path(int **edges, int n, int st, int en)
{
    vector<int> v;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    return getPath(edges, n, st, en, v, visited);
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

    vector<int> v = path(edges, n, st, en);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}