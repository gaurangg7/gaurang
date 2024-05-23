//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        // code here
         if (n < 3) {
        return 0;
    }
    
    // Sorting the array
    std::sort(arr, arr + n);
    
    int count = 0;
    
    // Loop through the array from right to left
    for (int i = n - 1; i >= 1; i--) {
        int l = 0; // Left pointer
        int r = i - 1; // Right pointer
        
        // Check for triangles
        while (l < r) {
            if (arr[l] + arr[r] > arr[i]) {
                count += r - l; // Counting triangles
                r--; // Move the right pointer to the left
            } else {
                l++; // Move the left pointer to the right
            }
        }
    }
    
    return count;
    }
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}
// } Driver Code Ends