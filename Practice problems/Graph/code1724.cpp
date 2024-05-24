//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	
	 int time = 0;

    bool bridgeUtil(int s, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<int>* adj, int c, int d) {
        visited[s] = true;
        disc[s] = ++time;
        low[s] = ++time;

        for (int j : adj[s]) {
            if (!visited[j]) {
                parent[j] = s;
                if (bridgeUtil(j, visited, disc, low, parent, adj, c, d)) {
                    return true;
                }
                low[s] = min(low[s], low[j]);
                if (low[j] > disc[s]) {
                    if ((c == j && d == s) || (c == s && d == j)) {
                        return true;
                    }
                }
            } else if (j != parent[s]) {
                low[s] = min(low[s], disc[j]);
            }
        }
        return false;
    }

	
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
         vector<bool> visited(V, false);
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        vector<int> parent(V, -1);
        time = 0;

        for (int i = 0; i < V; ++i) {
            if (!visited[i] && bridgeUtil(i, visited, disc, low, parent, adj, c, d)) {
                return 1;
            }
        }
        return 0;
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
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends