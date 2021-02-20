#include <bits/stdc++.h>
using namespace std;

void print(int **edges, int n, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            print(edges, n, i, visited);
        }
    }
}

void printBFS(int **edges, int n, int sv)
{
    queue<int> q;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    q.push(sv);
    visited[sv] = true;
    while (!q.empty())
    {
        int front = q.front();

        q.pop();
        cout << front << endl;
        for (int i = 0; i < n; i++)
        {
            if (i == front)
            {
                continue;
            }
            if (edges[front][i] == 1 && !visited[i])
            {
                //cout << i << endl;
                visited[i] = true;
                q.push(i);
            }
        }
        // fdelete visited
        delete[] visited;
    }
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
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    cout << "BFS" << endl;
    printBFS(edges, n, 0);

    cout << "DFS" << endl;
    print(edges, n, 0, visited);
    // delete memory
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}
