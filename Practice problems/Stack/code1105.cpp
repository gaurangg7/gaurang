//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
          int N = x.length();
    if (N % 2 != 0)
        return false;

    stack<char> st;
    for (int i = 0; i < N; i++) {
        char chr = x[i];
        if (chr == '[' || chr == '(' || chr == '{')
            st.push(chr);
        else {
            if (st.empty())
                return false;
            else if ((st.top() == '[' && chr == ']') || (st.top() == '(' && chr == ')') || (st.top() == '{' && chr == '}'))
                st.pop();
            else
                return false;
        }
    }

    return st.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends