//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
   void dfs(vector<vector<char>>&grid, int i, int j, int n, int m, vector<vector<bool>>&visited)
    {
        if(i<0||i>=n||j<0||j>=m||visited[i][j]==true||grid[i][j]=='0')
            return;
        
        visited[i][j]=true;
        dfs(grid,i+1,j,n,m,visited);
        dfs(grid,i-1,j,n,m,visited);
        dfs(grid,i,j+1,n,m,visited);
        dfs(grid,i,j-1,n,m,visited);
        dfs(grid,i+1,j+1,n,m,visited);
        dfs(grid,i-1,j-1,n,m,visited);
        dfs(grid,i-1,j+1,n,m,visited);
        dfs(grid,i+1,j-1,n,m,visited);
    }
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
           int count=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==false)
                {
                    dfs(grid,i,j,n,m,visited);
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends