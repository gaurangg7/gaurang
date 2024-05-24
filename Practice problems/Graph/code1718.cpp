//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
int isSafe(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited) {
    return (row >= 0) && (row < grid.size()) && (col >= 0) && (col < grid[0].size()) && (grid[row][col] == 1 && !visited[row][col]);
}

void dfs(vector<vector<int>>& grid, int l, int m, vector<vector<bool>>& visited, int& count) {
    static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    visited[l][m] = true;

    for (int k = 0; k < 8; ++k) {
        if (isSafe(grid, l + rowNbr[k], m + colNbr[k], visited)) {
            count++;
            dfs(grid, l + rowNbr[k], m + colNbr[k], visited, count);
        }
    }
}

    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
          
        int n = grid.size();
    if (n == 0) return 0;
    int m = grid[0].size();
    if (m == 0) return 0;

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                int count = 1;
                dfs(grid, i, j, visited, count);
                result = max(result, count);
            }
        }
    }
    return result;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends