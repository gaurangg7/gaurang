//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{ public:
    
    static int getLMB(int n)
    {
        int m = 0;
        while(n>1)
        {
            n = n>>1;
            m++;
            
        }
        return m ;
    }
    
    static int getNLMB( int n,int m )
    {
        int temp = 1<< m ;
        while(n< temp)
        {
            temp = temp >> 1;
            m--;
        }
        return m;
        
    }
    static int  countSetBits(int n)
    {
        // Your logic here
        int m = getLMB(n);
        return countSetBits( n , m);
    }
    static int  countSetBits( int n, int m)
    {
        if (n == 0)
        return 0;
        m = getNLMB(n, m);
        if (n == ((int)1<< (m+1)) - 1)
          return (int)(m + 1) *  (1<<m);
          n = n - (1 << m);
          return (n+1)+ countSetBits(n) + m * (1<< (m -1));
    }
        
    };



//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends
