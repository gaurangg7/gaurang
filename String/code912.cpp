//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        // Your code here
        vector<int> count(256, -1);
    int result = INT_MAX;

    for (int i = 0; i < str.length(); i++) {
        if (count[str[i]] == -1) {
            count[str[i]] = i;
        }
    }

    for (int i = 0; i < patt.length(); i++) {
        if (count[patt[i]] != -1) {
            result = min(result, count[patt[i]]);
        }
    }

    return (result != INT_MAX) ? result : -1;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        string str;
        string patt;
        cin>>str;
        cin>>patt;
        Solution obj;
        cout<<obj.minIndexChar(str, patt)<<endl;
    }
	return 0;
}

// } Driver Code Ends