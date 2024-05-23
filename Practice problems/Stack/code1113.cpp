//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
         stack<int> candidates;
    for (int i = 0; i < n; i++)
        candidates.push(i);

    while (candidates.size() >= 2) {
        int can1 = candidates.top();
        candidates.pop();
        int can2 = candidates.top();
        candidates.pop();

        if (M[can1][can2] == 1)
            candidates.push(can2);
        else
            candidates.push(can1);
    }

    int potentialCandidate = candidates.top();
    candidates.pop();

    for (int i = 0; i < n; i++) {
        if (i != potentialCandidate)
            if (M[potentialCandidate][i] == 1 || M[i][potentialCandidate] == 0)
                return -1;
    }
    return potentialCandidate;
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends