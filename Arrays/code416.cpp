//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
         bool indicator_array[n];
    for (int i = 0; i < n; ++i) {
        indicator_array[i] = arr[i] >= 0 ? true : false;
    }

    if (find(indicator_array, indicator_array + n, true) != indicator_array + n) {
        long long max_so_far = 0;
        long long max_ending_here = 0;
        for (int i = 0; i < n; ++i) {
            max_ending_here += arr[i];
            if (max_ending_here < 0) {
                max_ending_here = 0;
            }
            if (max_so_far < max_ending_here) {
                max_so_far = max_ending_here;
            }
        }
        return max_so_far;
    } else {
        long long max_val = arr[0];
        for (int i = 1; i < n; ++i) {
            if (arr[i] > max_val) {
                max_val = arr[i];
            }
        }
        return max_val;
    }
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends