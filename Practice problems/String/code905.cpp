//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to check if a string is subsequence of other string.
    bool isSubSequence(string A, string B)
    {
        //code here
         int i = 0; // Index for string A
    int j = 0; // Index for string B

    // Iterate over both strings
    while (i < A.length() && j < B.length()) {
        // If characters match, move to the next character in A
        if (A[i] == B[j]) {
            i++;
        }
        // Move to the next character in B
        j++;
    }

    // If all characters in A have been found in B in the same order
    // then A is a subsequence of B
    return (i == A.length());
    }
};

//{ Driver Code Starts.
    
int main() {
	
	int t;
	cin>>t;
	while(t--){
	    string A, B; cin>>A>>B;
	    Solution ob;
	    bool ans = ob.isSubSequence(A, B);
	    if(ans == true)
	        cout<<"True"<<endl;
	    else
	        cout<<"False"<<endl;
	}
	return 0;
}
// } Driver Code Ends