//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution
{
    public:
    //Function to find repeated character whose first appearance is leftmost.
    int repeatedCharacter (string s) 
    { 
        std::unordered_map<char, int> freqs;
    for (char c : s) {
        freqs[c]++;
    }

    // Find the index of the leftmost repeating character
    int minIndex = INT_MAX;
    for (char c : s) {
        if (freqs[c] > 1) {
            minIndex = std::min(minIndex, static_cast<int>(s.find(c)));
        }
    }

    return minIndex == INT_MAX ? -1 : minIndex;
    } 
};

//{ Driver Code Starts.


int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    string s;
	    cin>>s;
	    Solution obj;
	    int index = obj.repeatedCharacter(s); 
        if (index == -1) 
            cout<<-1<<endl;
        else
            cout<<s[index]<<endl;
	}
	return 0;
}

// } Driver Code Ends