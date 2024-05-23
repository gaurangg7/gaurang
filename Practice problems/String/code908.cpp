//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        unordered_map<char, int> freqs_a, freqs_b;
    for (char c : a) {
        freqs_a[c]++;
    }
    for (char c : b) {
        freqs_b[c]++;
    }
    
    // Check if the sets of characters are the same and the frequencies are equal
    if (std::set<char>(a.begin(), a.end()) == std::set<char>(b.begin(), b.end()) &&
        std::is_permutation(freqs_a.begin(), freqs_a.end(), freqs_b.begin())) {
        return true;
    } else {
        return false;
    }
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends