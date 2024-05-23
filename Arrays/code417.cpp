//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int totalsum(int arr[], int n)
    {
        int res=arr[0];
        int maxend=arr[0];
        for(int i=1; i<n; i++)
        {
            maxend= max(maxend+arr[i], arr[i]);
            res=max(res, maxend);
        }
        return res;
    }
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        int total=totalsum(arr, num);
        if(total<0)
           return total;
        
        int sum=0;
        for(int i=0; i<num; i++)
        {
            sum=sum+arr[i];
            arr[i]= -arr[i];
        }
         int max_cir= sum+totalsum(arr, num);
         return max(max_cir, total);
        
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends