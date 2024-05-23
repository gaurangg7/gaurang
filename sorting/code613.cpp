//{ Driver Code Starts
// A Sample C++ program for beginners with Competitive Programming

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    
    // A[]: input array
    // N: input array
    //Function to sort the binary array.
    void binSort(int A[], int N)
    {
       //Your code here
       
       /**************
        * No need to print the array
        * ************/
         int count0 = 0, count1 = 0;
    
    // Count the number of 0s and 1s in the array
    for (int i = 0; i < N; i++) {
        if (A[i] == 0)
            count0++;
        else
            count1++;
    }
    
    // Set the first count0 elements to 0 and the next count1 elements to 1
    for (int i = 0; i < count0; i++) {
        A[i] = 0;
    }
    for (int i = count0; i < count0 + count1; i++) {
        A[i] = 1;
    }
    }
};

//{ Driver Code Starts.
int main() {
	int T;
	cin>>T;
	// Input the number of testcases
	while(T--)
	{
	    int N;
	    cin>>N; //Input size of array N
	    int A[N]; 
	    
	    for(int i = 0; i  < N; i++)
	      cin>>A[i];
	      
	    Solution obj;
	    obj.binSort(A,N);
	    
	    for(int x:A)
	    cout<<x<<" ";
	      
	    cout<<endl;
	}
	return 0;
}




// } Driver Code Ends