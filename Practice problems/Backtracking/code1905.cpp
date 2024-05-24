//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    set<vector<int>>s;
    void helper(vector<int>&arr, int id, vector<int>ans){
        if(id == arr.size()){
            s.insert(ans);
            return;
        }
        int e = arr[id];
        helper(arr, id+1, ans);
        ans.push_back(e);
        helper(arr,id+1, ans);
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        sort(arr.begin(), arr.end());
        vector<int>ans;
        helper(arr, 0, ans);
        vector<vector<int>> res;
        for(auto e : s ){
            res.push_back(e);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends