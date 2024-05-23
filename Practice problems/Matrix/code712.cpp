//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public:
    //Function to reverse the columns of a matrix.
    void reverseCol(vector<vector<int> > &matrix)
    {
        // code here
         int n = matrix.size(); // Number of rows
    if (n == 0) return;    // Empty matrix

    int m = matrix[0].size(); // Number of columns
    if (m <= 1) return;        // Single column or empty matrix

    // Iterate over each column
    for (int j = 0; j < m / 2; j++) {
        // Swap elements of the j-th column with the (m - 1 - j)-th column
        for (int i = 0; i < n; i++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][m - 1 - j];
            matrix[i][m - 1 - j] = temp;
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
        ob.reverseCol(matrix);

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends