//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
         vector<vector<int> > adj_mat(V, vector<int>(V, 0));
        for(int i=0; i<V; i++)
            for(int j=0; j<adj[i].size(); j++)
                adj_mat[i][adj[i][j][0]] = adj[i][j][1];
        
           vector<int>dist(V,INT_MAX);
        dist[S]=0;
        vector<bool>fin(V,false);
        for(int i=0;i<V-1;i++)
        {
            int u=-1;
        for(int i=0;i<V;i++)
        {
            if((u==-1 || dist[u]>dist[i]  ) && !fin[i] )
            u=i;
        }
        fin[u]=true;
        for(int v=0;v<V;v++)
        if(adj_mat[u][v]!=0 && fin[v]==false)
        {
            dist[v]=min(dist[v],dist[u]+adj_mat[u][v]);
        }
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends