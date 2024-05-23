//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum number of consecutive steps 
    //to gain an increase in altitude with each step.
    int maxStep(int A[], int N)
    {
       //Your code here
        int maxStep = 0;
    int currentStep = 0;

    for (int i = 1; i < N; ++i) {
        if (A[i - 1] < A[i]) {
            currentStep = max(currentStep, 1);
            if (i >= 2 && A[i - 2] < A[i - 1])
                currentStep++;
        } else {
            currentStep = 0;
        }
        maxStep = max(maxStep, currentStep);
    }

    return maxStep;
    }
};

//{ Driver Code Starts.


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    Solution ob;
	    cout << ob.maxStep(a, n) << endl;
	}
	return 0;
}
// } Driver Code Ends