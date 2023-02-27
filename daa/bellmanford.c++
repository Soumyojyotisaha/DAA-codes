#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int source, dest;
    float wt;
};

int main()
{
    int vert, e;
    cout << "Enter number of vertices and edges: ";
    cin >> vert >> e;
    struct edge edges[e];
    cout << "Enter the source, destination, and weight of each edge: " << endl;
    for (int i = 0; i < e; i++)
        cin >> edges[i].source >> edges[i].dest >> edges[i].wt;

    float dist[vert];
    cout << "Enter the starting node: ";
    int start;
    cin >> start;
    for (int i = 0; i < vert; i++)
        dist[i] = INT_MAX;
    dist[start - 1] = 0;

    for (int i = 0; i < vert - 1; i++)
    {
        for (int j = 0; j < e; j++)
        {
            int u = edges[j].source;
            int v = edges[j].dest;
            float wt = edges[j].wt;
            if (dist[v - 1] > dist[u - 1] + wt)
                dist[v - 1] = dist[u - 1] + wt;
        }
    }

    int flag = 0;
    for (int j = 0; j < e; j++)
    {
        int u = edges[j].source;
        int v = edges[j].dest;
        float w = edges[j].wt;
        if (dist[v - 1] > dist[u - 1] + w)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        cout << "The distances from the starting node to each node are: " << endl;
        for (int i = 0; i < vert; i++)
            cout << dist[i] << endl;
    }
    else
        cout << "No solution" << endl;

    return 0;
}