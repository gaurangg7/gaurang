//{ Driver Code Starts
//Initial Template for C++


// CPP program to generate power set
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


//Function to return the lexicographically sorted power-set of the string.
vector <string> powerSet(string s)
{
   //Your code here
 vector<string> perm;
    if (s.length() == 0) {
        perm.push_back("");
        return perm;
    }
    char first = s[0];
    string rem = s.substr(1);
    vector<string> words = powerSet(rem);
    perm.insert(perm.end(), words.begin(), words.end());
    for (string word : words) {
        perm.push_back(first + word);
    }
    return perm;
       
  
   
}


//{ Driver Code Starts.


// Driver code
int main()
{
    int T;
    cin>>T;//testcases
    while(T--)
    {
        string s;
        cin>>s;//input string
        
        //calling powerSet() function
        vector<string> ans = powerSet(s);
        
        //sorting the result of the powerSet() function
        sort(ans.begin(),ans.end());
        
        //printing the result
        for(auto x:ans)
        cout<<x<<" ";
        cout<<endl;
        
        
    }

return 0;
} 
// } Driver Code Ends