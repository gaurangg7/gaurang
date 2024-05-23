//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        vector<int> rowSum(n, 0); // Stores the sum of each row
    vector<int> colSum(n, 0); // Stores the sum of each column

    // Calculate row and column sums
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rowSum[i] += matrix[i][j];
            colSum[j] += matrix[i][j];
        }
    }

    // Find the maximum sum among rows and columns
    int maxSum = max(*max_element(rowSum.begin(), rowSum.end()), *max_element(colSum.begin(), colSum.end()));

    int minOperations = 0;
    // Calculate the total number of operations required
    for (int i = 0; i < n; ++i) {
        minOperations += abs(maxSum - rowSum[i]);
        minOperations += abs(maxSum - colSum[i]);
    }

    // Divide by 2 because each operation counts twice (once for row, once for column)
    return minOperations / 2;
        
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends