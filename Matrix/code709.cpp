//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function for finding determinant of matrix.
    const int N = 10; // Assuming a maximum size for the matrix

void getCofactor(vector<vector<int>>& mat, vector<vector<int>>& temp, int p, int q, int n) {
    int i = 0, j = 0;

    // Looping for each element of the matrix
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // Copying into temporary matrix only those elements
            // which are not in the given row and column
            if (row != p && col != q) {
                temp[i][j++] = mat[row][col];

                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        // code here 
         if (n == 1)
        return matrix[0][0];

    int det = 0; // Initialize result

    // Iterate over each element of the first row
    for (int i = 0; i < n; i++) {
        // Calculate the cofactor matrix
        vector<vector<int>> cofactor(n - 1, vector<int>(n - 1));
        for (int j = 1; j < n; j++) {
            int k = 0;
            for (int l = 0; l < n; l++) {
                if (l != i) {
                    cofactor[j - 1][k++] = matrix[j][l];
                }
            }
        }

        // Calculate sign multiplier
        int sign = (i % 2 == 0) ? 1 : -1;

        // Calculate determinant recursively
        det += sign * matrix[0][i] * determinantOfMatrix(cofactor, n - 1);
    }

    return det;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends