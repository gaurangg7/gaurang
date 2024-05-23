//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
        unordered_map<char, int> charCount;

    // Count frequency of each character
    for (char c : S) {
        charCount[c]++;
    }

    // Find the first non-repeating character
    for (char c : S) {
        if (charCount[c] == 1) {
            return c;
        }
    }

    // If no non-repeating character found
    return '$';
      
    
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends