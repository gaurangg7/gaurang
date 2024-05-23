//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
       unordered_set<int> s;
        int i,res=0,curr;
        for (i= 0; i < N; i++)
            s.insert(arr[i]);
        for (i= 0; i< N; i++) {
            if (s.find(arr[i] - 1) == s.end())
            {
                curr = 1;
                while (s.find(curr+arr[i]) != s.end())
                    curr++;
                res= max(res, curr);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends