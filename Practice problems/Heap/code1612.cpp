//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to print kth largest element for each element in the stream.
    void kthLargest(int arr[], int n, int k)
    {
    	// your code here
    	priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<k-1;i++)
    {
        cout<<-1<<" ";
        pq.push(arr[i]);
    }
    
    for(int i=k-1;i<n;i++)
    {
        if(i==k-1)
        { 
            pq.push(arr[i]);
            cout<<pq.top()<<" ";
        }
        else if(arr[i]>pq.top())
        {
            pq.push(arr[i]);
            pq.pop();
            cout<<pq.top()<<" ";
            
        }
        else
        {
            cout<<pq.top()<<" ";
        }
        
    }
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k, n;
		cin>>k>>n;
	    
	    int arr[n];
	    for(int i = 0; i<n ; ++i)
	        cin>>arr[i];
        Solution ob;
	    ob.kthLargest(arr, n, k);
	    cout<<endl;
	    
	    
	}
	return 0;
}

// } Driver Code Ends