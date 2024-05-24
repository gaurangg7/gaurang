//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <fstream>
using namespace std;


// } Driver Code Ends
//User function Template for C++
// You need to complete this function


class Solution
{
    public:
    //Function to find the nth fibonacci number using bottom-up approach.
    // vector<long long int>mem(100,-1);
    vector<long long int> mem;

    // Constructor to initialize the memoization vector
    Solution() : mem(100, -1) {}
    long long findNthFibonacci(int n)
    {
        // Your Code Here
        if(n <= 1)return n;
        if(mem[n] != -1)return mem[n];
        else{
            return mem[n] = findNthFibonacci(n-1) + findNthFibonacci(n-2);
        }
    }
};


//{ Driver Code Starts.

int main()
 {
    //taking testcases
    int testcases;
    cin>>testcases;
    
    while(testcases--)
    {
        //taking nth fibonacci 
        //to be found
        int number;
        cin>>number;
        
        //calling function findNthFibonacci()
        //and passing number as parameter
        Solution obj;
        cout<<obj.findNthFibonacci(number)<<endl;
    }
    
	return 0;
}

// } Driver Code Ends