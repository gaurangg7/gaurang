//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    
    void dfs(int v, vector<int> adj[], vector<bool>& visited) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, adj, visited);
        }
    }
}
    
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    
	     vector<bool> visited(V, false);
    int lastVisited = 0;

    // Perform DFS from each vertex to find the last visited vertex
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            lastVisited = i;
        }
    }

    // Reset visited array
    fill(visited.begin(), visited.end(), false);

    // Perform DFS from the last visited vertex
    dfs(lastVisited, adj, visited);

    // Check if the last visited vertex is a mother vertex
    for (bool visit : visited) {
        if (!visit) {
            return -1; // No mother vertex found
        }
    }

    return lastVisited;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends