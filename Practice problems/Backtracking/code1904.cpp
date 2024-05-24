//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    
    void solve(string str, int k, string &maxx, int idx){
        if(k == 0) return ;
        int n = str.size();
        char maxm = str[idx];
        for(int j = idx +1; j<n; j++){
            if(maxm < str[j])
            maxm = str[j];
    
        }
        if(maxm != str[idx])
        --k;
        for(int j = idx; j<n;j++){
            if(str[j] == maxm){
                swap(str[idx], str[j]);
                
                if(str > maxx)
                maxx =str;
                
                solve(str, k, maxx, idx +1);
                swap(str[idx], str[j]);
                
            }
        }
    }
    
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
     string maxx = str;
     solve(str, k, maxx, 0);
     return maxx;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends