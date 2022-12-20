#include <bits/stdc++.h>
using namespace std;
int main()
{
    // n -> no. of vertex ,m-> no. of edges
    int n, m;
    cin >> n >> m;
    // cerate adjcency list
    unordered_map<int,list<pair<int,int>>> adj; 
    for (int i = 0; i < m; i++)                  
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u,w));
    }
    // creation of distance array with infinity values initially
    vector<int> dist(n+1); 
    for (int i = 0; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }

    // creation of set on basis of (distance,node)
    set<pair<int, int>> st; 
    int source;
    cin >> source;
    // initialse distance with source node
    dist[source] = 0;
    st.insert(make_pair(0, source));
    while (!st.empty())
    { 
        // fetch top record
        auto top = *(st.begin());
        int nodeDistance=top.first;
        int topNode=top.second;
        // remove top record now
        st.erase(st.begin());
        // traverse the neighbours
        for (auto neighbour: adj[topNode]) 
        {

           if(nodeDistance + neighbour.second < dist[neighbour.first])
           {
                auto record=st.find(make_pair(dist[neighbour.first],neighbour.first));
                // if record is found, erase it
                if(record != st.end())
                {
                    st.erase(record);
                }
                // distances update
                dist[neighbour.first] = nodeDistance + neighbour.second;
                // record push in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
           }
        }
    }
    for (int i = 1; i <=n; i++)
    {
        if (dist[i]<INT_MAX)
        {
            cout << dist[i] << " ";
        }
    }
}


/*
4 4
1 2 24
1 4 20
3 1 3
4 3 12
1
*/

/*
4 5
0 1 5
0 2 8
1 2 9
2 3 6
1 3 2
0
*/