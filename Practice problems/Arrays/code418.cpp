//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    //Function to find minimum adjacent difference in a circular array.
    // arr[]: input array
    // n: size of array
    int minAdjDiff(int arr[], int n){    
        // Your code here
        int min_diff = abs(arr[0] - arr[1]);
    for (int i = 1; i < n - 1; ++i) {
        int diff = abs(arr[i] - arr[i + 1]);
        if (diff < min_diff) {
            min_diff = diff;
        }
    }
    if (abs(arr[0] - arr[n - 1]) < min_diff) {
        min_diff = abs(arr[0] - arr[n - 1]);
    }
    return min_diff;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; //Input testcases
    
    while(t--) //While testcases exist
    {
        int n;
        cin>>n; //Input size of array
        
        int arr[n]; //Array of size n
        
        for(int i = 0; i < n; i++)
        {
            cin>>arr[i]; //input elements of array
        }
        Solution ob;
        
        cout << ob.minAdjDiff(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends