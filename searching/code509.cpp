//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        if (x == 0 || x == 1)
        return x;
    
    int start = 1, end = x, ans = 0;
    while (start <= end) {
        int mid = (start + end) / 2;
        
        // If x is a perfect square
        if (mid <= x / mid) {
            start = mid + 1;
            ans = mid;
        } else { // If mid*mid is greater than x, update end to mid-1
            end = mid - 1;
        }
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends