//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find repeated element and its frequency.
    pair<long, long> findRepeating(long *arr, int n){
        //code here
     //User function template for C++



        int count=1,elem=-1;
        
        for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            count++;
            elem=arr[i];
        }    
        }
        
         if (elem != -1) {
        return {elem, count};
    } else {
        return {-1, -1};
    }
    
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    long arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    Solution obj;
	    pair<long, long> ans = obj.findRepeating(arr,n);
	    
	    cout << ans.first << " " << ans.second << endl;
	    
	}
	
}
// } Driver Code Ends