//{ Driver Code Starts
//Initial Template for C++


#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    //Complete this function
    int digitalRoot(int n)
    {
        //Your code here
        if(n<10)
        return n ;
        return digitalRoot(digitalRoot(n/10) + n%10 ) %10;
    }
};

//{ Driver Code Starts.


int main() {
	int T;
	cin>>T;//taking testcases
	while(T--)
	{
	    int n;
	    cin>>n;//taking number n
	    
	    //calling digitalRoot() function
	    Solution obj;
	    cout<<obj.digitalRoot(n)<<endl;
	    
	    
	}
	return 0;
}
// } Driver Code Ends