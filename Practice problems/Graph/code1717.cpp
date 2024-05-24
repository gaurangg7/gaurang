//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
         int n = grid.size();
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    // Custom comparison function for the priority queue
    auto cmp = [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        return a.first > b.first;
    };
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> pq(cmp);

    dist[0][0] = grid[0][0];
    pq.push({dist[0][0], {0, 0}});

    while (!pq.empty()) {
        auto temp = pq.top();
        pq.pop();
        int dis = temp.first;
        int x = temp.second.first;
        int y = temp.second.second;
        visited[x][y] = true;

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny] && dist[nx][ny] > dis + grid[nx][ny]) {
                dist[nx][ny] = dis + grid[nx][ny];
                pq.push({dist[nx][ny], {nx, ny}});
            }
        }
    }

    return dist[n - 1][n - 1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends