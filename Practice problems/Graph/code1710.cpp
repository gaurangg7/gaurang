//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
            bool visited[V];
        int count=0;
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
        }
        queue<int>q;
        if(source==destination)
        count+=1;
        q.push(source);
        while(!q.empty())
        {
            int k=q.front();
            for(int u:adj[k])
            {
                if(u==destination)
                {
                    count++;
                }
                q.push(u);
            }
            q.pop();
        }
        return count;

    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}
// } Driver Code Ends