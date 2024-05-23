//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find lexicographic rank of a string.
    int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

    
    int findRank(string S) {
        // Your code here
              int n = S.length();
    int rank = 1;
    int fact = factorial(n);
    
    for (int i = 0; i < n; i++) {
        fact /= (n - i);
        int count_smaller = 0;
        for (int j = i + 1; j < n; j++) {
            if (S[j] < S[i]) {
                count_smaller++;
            }
        }
        rank += count_smaller * fact;
    }
    
    return rank;
    }
};

//{ Driver Code Starts.

int main() {
    string S;
    int t;
    cin >> t;
    while (t--) {

        cin >> S;
        Solution obj;
        cout << obj.findRank(S) << endl;
    }
}

// } Driver Code Ends