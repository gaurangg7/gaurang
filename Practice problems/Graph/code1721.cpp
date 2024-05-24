//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	 void dfs(vector<bool>& visited, vector<vector<int>>& adj, int x, stack<int>& st) {
    visited[x] = true;
    for (int i : adj[x]) {
        if (!visited[i]) {
            dfs(visited, adj, i, st);
        }
    }
    st.push(x);
}

void dfs2(vector<bool>& visited, vector<vector<int>>& adj, int x) {
    visited[x] = true;
    for (int i : adj[x]) {
        if (!visited[i]) {
            dfs2(visited, adj, i);
        }
    }
}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
          stack<int> st;
    vector<bool> visited(V, false);

    // Step 1: Perform DFS on the original graph and push vertices to stack after they are finished
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(visited, adj, i, st);
        }
    }

    // Step 2: Create the transpose of the graph
    vector<vector<int>> trans(V);
    for (int i = 0; i < V; i++) {
        for (int j : adj[i]) {
            trans[j].push_back(i);
        }
    }

    // Step 3: Reset visited array for the second DFS
    visited.assign(V, false);

    // Step 4: Perform DFS on the transposed graph, counting the number of strongly connected components
    int cnt = 0;
    while (!st.empty()) {
        int v = st.top();
        st.pop();
        if (!visited[v]) {
            dfs2(visited, trans, v);
            cnt++;
        }
    }

    return cnt;
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends