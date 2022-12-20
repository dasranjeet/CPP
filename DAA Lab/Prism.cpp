#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n);
    vector<bool> mst(n);
    vector<int> parent(n);

    for (int i = 0; i < n; i++)
    {
        key[i]=INT_MAX;
        parent[i]=-1;
        mst[i] = false;
    }

    key[0]=0;
    parent[0]=-1;

    for(int i=0; i < n; i++)
    {
        int mini=INT_MAX;
        int u;
        for(int v=0;v<=n;v++)
        {
            if(mst[v]==false && key[v]<mini)
            {
                u=v;
                mini=key[v];
            }
        }

        mst[u]=true;
        for(auto it:adj[u])
        {
            int v=it.first;
            int w=it.second;
            if(mst[v]== false && w<key[v])
            {
                parent[v]=u;
                key[v]=w;
            }
        }
    }


    for (int i = 1; i <n; i++)
        cout << parent[i] << " - " << i << " \n";

    return 0;
}

/*
4 5
0 1 10
1 2 15
0 2 5
3 1 2
3 2 40


0 - 1 
0 - 2 
1 - 3 
*/


/*
7 9
0 1 2
1 2 16
1 6 14
2 3 12
3 4 22
3 6 18
4 5 25
4 6 24
5 0 10
*/