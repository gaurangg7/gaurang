//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to multiply two matrices.
    vector<vector<int> > multiplyMatrix( const vector<vector<int> >& a, const vector<vector<int> >& b)
    {
        // code here
         vector<vector<int>>result;
        
        int n1=a.size();
        int m1=a[0].size();
        
        int n2=b.size();
        int m2=b[0].size();
        
        if(m1==n2)
        {
            result.resize(n1);
            for(int i=0;i<n1;i++)
            {
                result[i].assign(m2,0);
                for(int j=0;j<m2;j++)
                {
                    int sum=0; 
                    for(int k=0; k<m1; k++)
                    {
                       sum += a[i][k] * b[k][j]; 
                    } 
                    result[i][j] = sum;
                }
                
            }
            
        }
        return result;
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
        vector<vector<int> > A(row); 
        for(int i=0; i<row; i++)
        {
            A[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>A[i][j];
            }
        }
        cin>> row>> col;
        vector<vector<int> > B(row);
        for(int i=0; i<row; i++)
        {
            B[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>B[i][j];
            }
        }
        Solution ob;
        vector<vector<int> > result = ob.multiplyMatrix(A,B);

        if(result.size() == 0)
            cout<<"-1";
        else
        {
            for (int i = 0; i < result.size(); ++i)
            {
                for (int j = 0; j < result[0].size(); ++j)
                {
                    cout<<result[i][j]<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends