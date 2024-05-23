//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	 sort(arr, arr + n);
    sort(dep, dep + n);
    
    // Initializing variables
    int plat_needed = 1; // Number of platforms needed at the current time
    int result = 1; // Maximum platforms needed at any time
    
    // Pointers for arrival and departure times
    int i = 1, j = 0;
    
    // Loop through arrival and departure times
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            plat_needed++; // Increment platforms needed if train arrives
            i++; // Move to the next arrival time
        } else {
            plat_needed--; // Decrement platforms needed if train departs
            j++; // Move to the next departure time
        }
        
        // Update the maximum platforms needed
        result = max(result, plat_needed);
    }
    
    return result;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends