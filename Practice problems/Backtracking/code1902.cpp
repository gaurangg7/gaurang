//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:


bool isSafe(bool graph[101][101], int colors[], int v, int c, int n) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && c == colors[i])
            return false;
    }
    return true;
}

bool graphColoringUtil(bool graph[101][101], int m, int colors[], int v, int n) {
    if (v == n)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, colors, v, c, n)) {
            colors[v] = c;
            if (graphColoringUtil(graph, m, colors, v + 1, n))
                return true;
            colors[v] = 0;
        }
    }
    return false;
}

    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
          int colors[n] = {0};

    if (!graphColoringUtil(graph, m, colors, 0, n))
        return false;

    return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends