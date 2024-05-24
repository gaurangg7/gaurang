//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        vector<int> result;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int k = min(K, num - 1);
    for (int i = 0; i <= k; i++) {
        minHeap.push(arr[i]);
    }

    result.push_back(minHeap.top());
    minHeap.pop();

    for (int i = K + 1; i < num; i++) {
        minHeap.push(arr[i]);
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    return result;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends