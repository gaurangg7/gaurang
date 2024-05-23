//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
         stringstream ss(S); // Using stringstream to split the string by '.'
    vector<string> tokens;
    string token;

    // Splitting the string by '.'
    while (getline(ss, token, '.')) {
        tokens.push_back(token);
    }

    // Reversing the tokens
    reverse(tokens.begin(), tokens.end());

    // Joining the reversed tokens with '.'
    string result = "";
    for (int i = 0; i < tokens.size(); ++i) {
        result += tokens[i];
        if (i != tokens.size() - 1) {
            result += ".";
        }
    }

    return result;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends