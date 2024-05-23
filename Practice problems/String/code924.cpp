//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
      std::unordered_set<char> letters;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        letters.insert(ch);
    }
    
    for (char &ch : s) {
        if (std::isalpha(ch)) {
            ch = std::tolower(ch);
            letters.erase(ch);
        }
    }
    
    return letters.empty();
    
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends