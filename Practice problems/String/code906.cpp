//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        unordered_map<char, int> freqs;
    for (char c : str) {
        freqs[c]++;
    }

    // Find the maximum frequency
    int maxO = 0;
    for (auto& pair : freqs) {
        maxO = std::max(maxO, pair.second);
    }

    // Find characters with maximum frequency
    std::vector<char> chars;
    for (char c : str) {
        if (freqs[c] == maxO) {
            chars.push_back(c);
        }
    }

    // If only one character has the maximum frequency, return it
    if (chars.size() == 1) {
        return chars[0];
    } else {
        // If multiple characters have the maximum frequency, return the smallest one
        char minChar = chars[0];
        for (char c : chars) {
            if (c < minChar) {
                minChar = c;
            }
        }
        return minChar;
    }
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends