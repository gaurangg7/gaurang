//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find the median of the two arrays when they get merged.
    int findMedian(int arr[], int n, int brr[], int m)
    {
        // code here
         vector<int> ar(arr, arr + n);
    std::vector<int> br(brr, brr + m);
    
    std::vector<int> merged;
    merged.reserve(n + m);
    merged.insert(merged.end(), ar.begin(), ar.end());
    merged.insert(merged.end(), br.begin(), br.end());

    std::sort(merged.begin(), merged.end());

    if ((n + m) % 2 == 0) {
        int a = merged[((n + m) / 2) - 1];
        int b = merged[((n + m) / 2)];
        return std::floor((a + b) / 2);
    } else {
        return merged[((n + m + 1) / 2) - 1];
    }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    int arr[n];
	    int brr[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> brr[i];
	    }
	    Solution obj;
	    if(n < m)
	        cout << obj.findMedian(arr, n, brr, m) << endl;
	   else
	        cout << obj.findMedian(brr, m, arr, n) << endl;
	    
	}

}
// } Driver Code Ends