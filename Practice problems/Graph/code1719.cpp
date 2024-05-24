//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct myCmp
    {
        bool operator() (pair<int,int> &p1,pair<int,int> &p2)
        {
        return (p1.second > p2.second);
        }
    };
    
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
          priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
        pq.push({0,0});
        unordered_set<int> visited;
        int total_cost=0;
        while(!pq.empty()){
            pair<int,int> u=pq.top();
            pq.pop();
            int node=u.second;
            if(visited.count(node)) continue;
            visited.insert(node);
            total_cost+=u.first;
            for(auto v:adj[node]){
                int neighbour=v[0];
                if(visited.count(neighbour)) continue;
                pq.push({v[1],v[0]});
            }
        }
        return total_cost;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends