//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    //Function to fill the array elements into a hash table 
    //using Quadratic Probing to handle collisions.
    void QuadraticProbing(vector <int>&hash, int hashSize, int arr[], int N)
    {
        //Your code here
        for(int i =0;i<N;i++){
           int key = arr[i]%hashSize;
           vector<int>::iterator it;
           it = find(hash.begin(), hash.end(), arr[i]);
           if(it != hash.end()){
               continue;
           }
            if(hash[key] == -1){
                hash[key] = arr[i];
            }else{
                int temp = 1;
                while(hash[(key+temp*temp)%hashSize]!=-1){
                temp++;
                }
                hash[(key+temp*temp)%hashSize] = arr[i];
            }
        }
    }


};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int hashSize;
	    cin>>hashSize;
	    
	    
	    int  N;
	    cin>>N;
	    int arr[N];
	    
	    for(int i=0;i<N;i++)
	    cin>>arr[i];
	    
	    vector<int> hash (hashSize,-1);
	    Solution obj;
	    obj.QuadraticProbing (hash, hashSize, arr, N);
	    
	    for(int i = 0;i < hashSize; i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	}
	return 0;
}



// } Driver Code Ends