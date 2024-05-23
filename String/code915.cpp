//{ Driver Code Starts
// C++ program Find concatenated string with 
// uncommon characters of given strings 
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends


class Solution
{
    public:
    //Function to remove common characters and concatenate two strings.
    string concatenatedString(string s1, string s2) 
    { 
        // Your code here
           unordered_set<char> set1(s1.begin(), s1.end());
    unordered_set<char> set2(s2.begin(), s2.end());

    string result;

    for (char c : s1) {
        if (set2.find(c) == set2.end()) {
            result.push_back(c);
        }
    }

    for (char c : s2) {
        if (set1.find(c) == set1.end()) {
            result.push_back(c);
        }
    }

    if (result.empty()) {
        return "-1";
    } else {
        return result;
    }
    }

};

//{ Driver Code Starts.

/* Driver program to test above function */
int main() 
{ 
	int t;
	cin >> t;
	
	while(t--){
    	string s1, s2;
    	cin >> s1 >> s2;
    	Solution obj;
    	string res = obj.concatenatedString(s1, s2);
    	cout<<res<<endl;
	}
	return 0; 
}

// } Driver Code Ends