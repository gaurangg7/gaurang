//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // code here 
         int rows = matrix.size();
    if (rows == 0) return; // Empty matrix

    int cols = matrix[0].size();

    unordered_map<int, int> rowMap, colMap;

    // Scan the matrix and mark rows and columns containing 1
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 1) {
                rowMap[i] = 1;
                colMap[j] = 1;
            }
        }
    }

    // Update the matrix based on the marked rows and columns
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (rowMap.find(i) != rowMap.end() || colMap.find(j) != colMap.end()) {
                matrix[i][j] = 1;
            }
        }
    }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends