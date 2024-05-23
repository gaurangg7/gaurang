//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        if (s1.length() != s2.length() || s1.length() == 0)
        return false;

    // Concatenate s1 with itself to form a new string
    std::string concatenated = s1 + s1;

    // Check if s2 is a substring of the concatenated string
    if (concatenated.find(s2) != std::string::npos)
        return true;
    else
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends