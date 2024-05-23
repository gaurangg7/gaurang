//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if a string is Isogram or not.
    bool isIsogram(string s)
    {
        //Your code here
        unordered_map<char, int> freqs;
    for (char c : s) {
        freqs[c]++;
    }

    // Check if any character has a frequency greater than 1
    for (auto& pair : freqs) {
        if (pair.second > 1) {
            return false; // Not an isogram
        }
    }

    return true; // All characters have frequency 1, so it's an isogram
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.isIsogram(s)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends