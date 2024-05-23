//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
 
class Solution
{
  
    // Function for finding maximum AND value.
    int CB( int p, int arr[], int n)
    {
        int count = 0;
        for (int i= 0 ; i<n;i++)
        if ((p & arr[i]) == p)
        count ++;
        return count ;
        
    }
      public:
    int maxAND (int arr[], int n)
    {
        // Your code here
        int res = 0, count ;
        for (int bit =31;bit>=0;bit--)
        {
            count = CB(res | (1<< bit ), arr, n);
            if (count >=2)
            res |= (1<<bit);
        }
        return res;
        
    }
};

//{ Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;//testcases
    while(t--)
    {
        int n;
        cin>>n;//input n
        int arr[n+5],i;
        
        //inserting elements
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        //calling maxAND() function
        cout <<  obj.maxAND(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends