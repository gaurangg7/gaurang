//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        
        // Your code here
 string gray_rep = bitset<32>(n).to_string(); // Convert integer to binary string
    string binary;
    binary.push_back(gray_rep[0]);
    
    for (size_t i = 1; i < gray_rep.length(); ++i) {
        if (gray_rep[i] == '0') {
            binary.push_back(binary[i - 1]);
        } else {
            binary.push_back((binary[i - 1] == '0') ? '1' : '0');
        }
    }
    return stoi(binary, nullptr, 2);
        
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends