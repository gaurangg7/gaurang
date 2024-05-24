//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private: 
        bool dfs(int start,vector<int> adj[], vector<int>&visited, vector<int>& path)
        {
            visited[start]=1;
            path[start]=1;
            int size = adj[start].size();
            for(int i=0;i<size;i++)
            {
                int temp=adj[start][i];
                if(visited[temp]==1)
                {
                    if(path[temp]==1)
                    return true;
                    else
                    {
                        continue;
                    }
                    
                }
                else if(dfs(temp,adj,visited,path)==true)
                {
                    return true;
                }
            }
            path[start]=0;
            return false;
        };
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>visited(V,0);
        vector<int>path(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,adj,visited,path)==true)
                return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends