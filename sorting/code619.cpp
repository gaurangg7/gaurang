//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A, A + n);
    
    // Loop through the array from the beginning
    for (int i = 0; i < n - 2; i++) {
        int l = i + 1; // Left pointer
        int r = n - 1; // Right pointer
        
        // Use two pointers to find the sum of three elements
        while (l < r) {
            int cur_sum = A[i] + A[l] + A[r];
            if (cur_sum == X) {
                return true; // If sum is equal to X, return true
            } else if (cur_sum < X) {
                l++; // If sum is less than X, move the left pointer to the right
            } else {
                r--; // If sum is greater than X, move the right pointer to the left
            }
        }
    }
    
    return false; 
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends