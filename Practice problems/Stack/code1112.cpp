//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
          stack<int> st;
    vector<int> ps = getPreviousSmaller(arr, n, st);
    while (!st.empty()) st.pop(); // Clear the stack
    vector<int> ns = getNextSmaller(arr, n, st);

    long long res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, (static_cast<long long>(ns[i] - ps[i] - 1) * arr[i]));
    }
    return res;
    }
    vector<int> getPreviousSmaller(long long arr[], int N, stack<int>& st) {
    vector<int> ps(N);
    for (int i = 0; i < N; i++) {
        while (!st.empty() && arr[i] <= arr[st.top()])
            st.pop();

        ps[i] = (st.empty()) ? -1 : st.top();
        st.push(i);
    }
    return ps;
}

vector<int> getNextSmaller(long long arr[], int N, stack<int>& st) {
    vector<int> ns(N);
    for (int i = N - 1; i >= 0; i--) {
        while (!st.empty() && arr[i] <= arr[st.top()])
            st.pop();

        ns[i] = (st.empty()) ? N : st.top();
        st.push(i);
    }
    return ns;}
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends