//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
         stack<int> s;
    queue<int> modifiedQueue;

    int n = q.size();
    
    // Push all elements from the queue to the stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Pop elements from the stack and enqueue them to the modified queue
    while (!s.empty()) {
        modifiedQueue.push(s.top());
        s.pop();
    }

    int i = 1;
    // Pop k elements from the front of the modified queue and push them back to the stack
    while (i <= n - k) {
        s.push(modifiedQueue.front());
        modifiedQueue.pop();
        i++;
    }

    // Pop elements from the stack and enqueue them back to the modified queue
    while (!s.empty()) {
        modifiedQueue.push(s.top());
        s.pop();
    }

    return modifiedQueue;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends