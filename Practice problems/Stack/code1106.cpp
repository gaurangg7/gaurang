//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to remove consecutive duplicates from given string using Stack.
    string removeConsecutiveDuplicates(string str)
    {
        // Your code here
         stack<char> unique;

    for (int i = 0; i < str.length(); i++) {
        char x = str[i];
        if (unique.empty() || unique.top() != x)
            unique.push(x);
    }

    string result = "";
    while (!unique.empty()) {
        result = unique.top() + result;
        unique.pop();
    }

    return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.removeConsecutiveDuplicates(s)<<endl;
    }
    
	return 0;
}
// } Driver Code Ends