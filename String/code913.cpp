//{ Driver Code Starts
#include<bits/stdc++.h>
#define br char xx; cin>>xx; cout<<xx<<endl;
#define lli long long int
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of characters which Ishaan must insert  
    //such that string doesn't have three consecutive same characters.
    int modified (string a)
    {
        // Your code here
         int start = 0;
    int end = 0;
    int count = 0;
    long result = 0;
    
    while (start <= end && end < a.length()) {
        if (a[start] == a[end]) {
            end++;
            count++;
        } else {
            count = 0;
            start = end;
        }
        
        if (count == 3) {
            result++;
            end--;
            start = end;
            count = 0;
        }
    } 
    return result;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    string a;
    while(t--){
        cin>>a;
        Solution obj;
        cout<<obj.modified(a)<<endl;
    }
    return 0;
}

// } Driver Code Ends