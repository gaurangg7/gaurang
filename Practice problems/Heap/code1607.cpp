//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        vector<int> result;
    
    // Check if the array size is less than k
    if (n < k) {
        // Handle the case where there are fewer elements than requested
        return result; // Return an empty vector
    }

    // Create a min-heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert the first k elements into the min-heap
    for (int i = 0; i < k; i++)
        minHeap.push(arr[i]);

    // Process the remaining elements
    for (int i = k; i < n; i++) {
        // If the current element is greater than the top of the min-heap
        if (arr[i] > minHeap.top()) {
            // Remove the smallest element from the min-heap
            minHeap.pop();
            // Insert the current element into the min-heap
            minHeap.push(arr[i]);
        }
    }

    // Extract elements from the min-heap and store them in the result vector
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    
    // Reverse the result vector to get the k largest elements in descending order
    reverse(result.begin(), result.end());

    return result;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        for(int i = 0; i < n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout << endl;
        
    }
    return 0;
}

// } Driver Code Ends