//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to remove pair of duplicates from given string using Stack.
    string removePair(string str)
    {
        // Your code here
        stack<char> st;

    for (char x : str) {
        if (!st.empty() && st.top() == x)
            st.pop();
        else
            st.push(x);
    }

    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
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
        string ans = obj.removePair (s);
        if(ans=="")
            cout<<"Empty String"<<endl;
        else
            cout<<ans<<endl;
    }
    
	return 0;
}
// } Driver Code Ends