//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
// Function to print the k numbers with most occurrences 

class Solution
{
    public:
    struct mycmp{
      bool operator()(pair<int,int> p1,pair<int,int> p2){
          if(p1.second==p2.second){
              return p1.first>p2.first;
          }
          return p1.second<p2.second;;
      }
    };
    //Function to return the sum of frequencies of k numbers
    //with most occurrences in an array.
    int kMostFrequent(int arr[], int n, int k) 
    { 
    	// Your code here
    	int sum=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycmp> pq(m.begin(),m.end());
        for(int i=0;i<k;i++){
            sum=sum + pq.top().second;
            pq.pop();
        }
        return sum;

    } 
};

//{ Driver Code Starts.
// Driver program to test above 
int main() 
{
	int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.kMostFrequent(arr, n, k) << endl; 
    }

	return 0; 
} 

// } Driver Code Ends