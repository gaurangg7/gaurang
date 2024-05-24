//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++
class Solution
{
 struct comap 
    {
        bool operator()(const pair<int, pair<int, int>>& p1, const pair<int, pair<int, int>>& p2)
        {
            return p1.first > p2.first;
        }
    };

    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comap> pq;
        for(int i = 0; i < K; i++)
        {
            pq.push({arr[i][0], {i, 0}});
        }
        vector<int> ret;
        ret.reserve(K*K); // Reserve space for K*K elements
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            ret.push_back(top.first);
            int row = top.second.first;
            int col = top.second.second;
            if(col + 1 < K)
            {
                pq.push({arr[row][col + 1], {row, col + 1}});
            }
        }
        return ret;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends