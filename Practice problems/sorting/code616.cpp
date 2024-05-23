//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        // code here
         int count[27] = {0};
        int len = arr.length();
        
        for(int i=0;i<len;i++){
            count[int(arr[i])-97]++;
        }
        
        for(int i=1;i<27;i++){
            count[i] += count[i-1];
        }
        
        int temp[len] = {0};
        for(int j=len-1;j>=0;j--){
            temp[count[int(arr[j])-97]-1] = arr[j];
            count[int(arr[j]) - 97]--;
        }
        for(int i=0;i<len;i++){
            arr[i] = temp[i];
        }
        return arr;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    }
    return 0;
}

// } Driver Code Ends