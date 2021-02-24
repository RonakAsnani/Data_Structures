/*Kruskal's Algorithm
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
MST
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
1 2 1
0 1 3
0 3 5
	*/

#include <bits/stdc++.h>
using namespace std;
/*
class Edge
{
public:
    int source;
    int destination;
    int weight;
};


// int par(int x, int parent[], int n)
// {
//     int ans;

//     if (parent[x] == x)
//     {
//         ans = x;
//     }
//     else
//     {
//         ans = par(parent[x], parent, n);
//     }
//     return ans;
// }


bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

void krukal(int n, int e, Edge *input)
{
    Edge *output = new Edge[n - 1];
    sort(input, input + e, compare);
    int parent[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int count = 0;
    int x = 0;
    while (count < n - 1)
    {
        // Edge curr = input[x];

        int p1 = par(input[x].source, parent, n);
        int p2 = par(input[x].destination, parent, n);

        // union by find
        /*  if (p1 != p2)
        {
            output[count].source = input[x].source;
            output[count].destination = input[x].destination;
            output[count].weight = input[x].weight;
            // cout << input[x].source << " " << input[x].destination << " " << input[i].weight << endl;
            count++;
            parent[p1] = p2;
        }
        x++;
    

        // union by rank
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (output[i].source < output[i].destination)
        {
            cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;
        }
        else
        {
            cout << output[i].destination << " " << output[i].source << " " << output[i].weight << endl;
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    Edge *input = new Edge[e];
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].destination = d;

        input[i].weight = w;
    }
    // Edge *output = new Edge[n - 1];

    //krukal(n, e, input);
    // for (int i = 0; i < n - 1; i++)
    // {
    //     cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;
    // }



    return 0;
}
*/

class Edge
{
public:
    int source;
    int dest;
    int weight;
};

class Disjnt
{
public:
    int rank;
    int parent;
};

int find(Disjnt *ds, int x)
{
    if (ds[x].parent != x)
    {
        ds[x].parent = find(ds, ds[x].parent);
    }
}

void Union(Disjnt *ds, int x, int y)
{
    int rootX = find(ds, x);
    int rootY = find(ds, y);
    if (ds[rootX].rank < ds[rootY].rank)
    {
        ds[rootX].parent = rootY;
    }
    else if (ds[rootX].rank > ds[rootY].rank)
    {
        ds[rootY].parent = rootX;
    }
    else
    {
        ds[rootX].parent = rootY;
        ds[rootY].rank++;
    }
}

bool isUnion(Disjnt *ds, int x, int y)
{
    return find(ds, x) == find(ds, y);
}

void KruskalMST(Edge *input, Disjnt *ds, int n, int e)
{
    vector<Edge> v;
    int j = 0;
    for (int i = 0; i < e && j < n - 1; i++)
    {
        if (!isUnion(ds, input[i].source, input[i].dest))
        {
            Union(ds, input[i].source, input[i].dest);
            v.push_back(input[i]);
            j++;
        }
    }
}

bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int main()
{
    int n, e;
    cin >> n >> e;
    Edge *input = new Edge[e];
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }
    Disjnt *ds = new Disjnt[n];
    for (int i = 0; i < n; i++)
    {
        ds[i].parent = i;
        ds[i].rank = 0;
    }

    sort(input, input + e, compare);

    KruskalMST(input, ds, n, e);
}