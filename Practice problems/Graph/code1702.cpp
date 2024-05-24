//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int n, vector<int> g[]) {
        // Code here
        vector<int>ans;
        int visited[n]={0};
        
        queue<int>q;
         int s=0;
         if(visited[s]==0)
         {
             ans.push_back(s);
             q.push(s);
              visited[s]=1;
         }
      
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            if(visited[u]==0)
            {
                ans.push_back(u);
            }
            visited[u]=1;
            for(auto x:g[u])
            {
                if(!visited[x])
                {
                    q.push(x);
                }
            }
        }
        return ans ;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends