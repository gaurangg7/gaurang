//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to count the number of subarrays which adds to the given sum.
    int subArraySum(int arr[], int n, int sum)
    {
        //Your code here
        unordered_map<int, int> hm;
    
    int prefixSum = 0;
    int count = 0;
    hm[0] = 1;
    
    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];
        
        if(hm.find(prefixSum - sum) != hm.end()) {
            count += hm[prefixSum - sum];
        }
        
        if(hm.find(prefixSum) == hm.end()) {
            hm[prefixSum] = 1;
        } else {
            hm[prefixSum]++;
        }
    }
    return count;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,sum=0;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>sum;
	    Solution obj;
	    cout<<obj.subArraySum(arr, n, sum)<<endl;
	}
	return 0;
}
// } Driver Code Ends