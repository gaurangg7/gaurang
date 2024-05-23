//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

void solve(int N, vector<int> &ans)
{
    if(N<=0)
    {
        ans.push_back(N);
        return;
        
    }
    ans.push_back(N);
    solve(N-5,ans);
    ans.push_back(N);
    return;
    
}

vector<int> pattern(int N) {
    vector<int> ans;
    solve(N, ans);
    return ans;
}


};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends