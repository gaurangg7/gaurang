//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int N)
    {
        // Your code here
        stack<int> st;
    vector<int> op(N, 0);
    
    vector<int> ps = previousSmaller(arr, N, st);
    st = stack<int>(); // Clear the stack
    vector<int> ns = nextSmaller(arr, N, st);
    st = stack<int>(); // Clear the stack
    
    for (int i = 0; i < N; i++) {
        int index = ns[i] - ps[i] - 2;
        op[index] = max(op[index], arr[i]);
    }
    
    for (int i = N - 2; i >= 1; i--) {
        op[i] = max(op[i + 1], op[i]);
    }
    
    return op;
    }
    vector<int> previousSmaller(int arr[], int N, stack<int>& st) {
    vector<int> ps(N);
    for (int i = 0; i < N; i++) {
        while (!st.empty() && arr[i] <= arr[st.top()])
            st.pop();

        ps[i] = (st.empty()) ? -1 : st.top();
        st.push(i);
    }
    return ps;
}

vector<int> nextSmaller(int arr[], int N, stack<int>& st) {
    vector<int> ns(N);
    for (int i = N - 1; i >= 0; i--) {
        while (!st.empty() && arr[i] <= arr[st.top()])
            st.pop();

        ns[i] = (st.empty()) ? N : st.top();
        st.push(i);
    }
    return ns;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends