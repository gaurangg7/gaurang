//{ Driver Code Starts
// C++ program for Naive Pattern 
// Searching algorithm 
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if the given pattern exists in the given string or not.
    bool search(string pat, string txt) 
    { 
    	
    	// Your code here
    	 
        int	n = txt.length();
        int m = pat.length();
        for(int i = 0; i < n; i++)
        {
            int j;
            for(j = 0; j < m; j++)
            {
                if(txt[i+j] != pat[j])
                break;
            }
            if(j == m)
            return true;
        }
        return false;
    	
    }
};


//{ Driver Code Starts.

// Driver Code 
int main() 
{ 
	
	int t;
	cin >> t;
	
	while(t--){
	    string s, p;
	    cin >> s >> p;
	    Solution obj;
	    if(obj.search(p, s)) cout << "Yes"; else cout << "No"; cout << endl;
	}
	
	return 0; 
}

// } Driver Code Ends