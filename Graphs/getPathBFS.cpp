/*Code : Get Path - BFS
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
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
3 0 1*/

#include <bits/stdc++.h>
using namespace std;

vector<int> *getPathBFS(int **edges, int n, int st, int en)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    queue<int> q;
    q.push(st);
    visited[st] = 1;
    vector<int> *v = new vector<int>();
    unordered_map<int, int> m;
    int ans = false;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                continue;
            }
            if (edges[front][i] == 1)
            {
                q.push(i);
                visited[i] = true;
                m[i] = front;
                if (i == en)
                {
                    ans = true;
                    break;
                }
            }
        }
    }
    delete[] visited;
    if (!ans)
    {
        return NULL;
    }
    else
    {
        int curr = en;
        v->push_back(curr);
        while (curr != st)
        {
            curr = m[curr];
            v->push_back(curr);
        }
    }
    return v;
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
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int st, en;
    cin >> st >> en;

    vector<int> *v = getPathBFS(edges, n, st, en);

    for (int i = 0; i < v->size(); i++)
    {
        cout << v->at(i) << " ";
    }

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}