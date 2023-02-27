#include<bits/stdc++.h>
using namespace std;

const int n = 4;

struct Node
{
    int id, state, pred;
};

bool bfs(Node vert[], Node source, Node sink, int res[][n])
{
    Node u;
    int i, j;
    queue<Node> q;
    for(i = 0; i < n; i++)
    {
        vert[i].state = 0;
    }
    vert[source.id].state = 1;
    vert[source.id].pred = -1;
    q.push(source);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(i = 0; i < n; i++)
        {
            if(res[u.id][i] > 0 && vert[i].state == 0)
            {
                q.push(vert[i]);
                vert[i].state = 1;
                vert[i].pred = u.id;
            }
        }  
    }
    return vert[sink.id].state == 1;
}

int fordFulkerson(int res[][n], Node source, Node sink)
{
    Node vert[n] = {{0, 0, 0}, {1, 0, 0}, {2, 0, 0}, {3, 0, 0}};
    int i, j, max_flow = 0;
    while(bfs(vert, source, sink, res))
    {
        int path_flow = INT_MAX;
        for(i = sink.id; i != source.id; i = vert[i].pred)
        {
            j = vert[i].pred;
            path_flow = min(path_flow, res[j][i]);
        }
        for(i = sink.id; i != source.id; i = vert[i].pred)
        {
            j = vert[i].pred;
            res[j][i] -= path_flow;
            res[i][j] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main()
{
    int res[n][n] = {{0, 3, 2, 0},
                     {0, 0, 5, 2},
                     {0, 0, 0, 3},
                     {0, 0, 0, 0}};
    Node source = {0, 0, -1};
    Node sink = {3, 0, -1};
    int max_flow = fordFulkerson(res, source, sink);
    cout << "Maximum flow: " << max_flow << endl;
    return 0;
}
