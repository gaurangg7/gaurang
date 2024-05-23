//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
        int betBalance(string result)
        {
            int current_sum = 4;  // Initial sum
    int bet_amount = 1;   // Initial bet amount for the 1st round

    for (char outcome : result) {
        // Check if current sum is negative before updating
        if (current_sum <= 0 || current_sum < bet_amount) {
            return -1;
        }

        if (outcome == 'W') {
            current_sum += bet_amount;
            bet_amount = 1;  // Reset bet amount to $1 after winning
        } else if (outcome == 'L') {
            current_sum -= bet_amount;
            bet_amount *= 2; // Double the bet amount after losing
        }

        // Check if the current sum is enough to continue the game
       
    }

    return (current_sum < 0) ? -1 : current_sum;
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string result;
        cin>>result;
        
        Solution ob;
        cout<<ob.betBalance(result)<<endl;
    }
    return 0;
}
// } Driver Code Ends