//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    // Function to count number of Ones
    // arr: input array 
    // N: size of input array
    int countOnes(int arr[], int N)
    {
        
        // Your code here
        int low = 0;
    int high = N - 1;
  
    // Binary search
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // If the mid element is 1, then all elements to its right are also 1
        // So, move to the left to find the leftmost occurrence of 1
        if (arr[mid] == 1)
            low = mid + 1;
        else // If the mid element is 0, move to the right
            high = mid -1 ;
    }
    
    // Number of 1s will be the index of the first occurrence of 0
    // If no 0 found, then all elements are 1s
    return low;
   
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
        int *arr = new int[n]; 
        for(int i = 0; i < n; i++)
            cin>>arr[i];
            
        Solution ob;
        cout <<ob.countOnes(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends