//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long tohu(int N, int from, int to, int aux) {
        // Your code here
        if (N == 1) {
        cout << "move disk 1 from rod " << from << " to rod " << to << endl;
        return 1;
    } else {
        long long steps = 0;
        steps += tohu(N - 1, from, aux, to);
        cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
        steps++;
        steps += tohu(N - 1, aux, to, from);
        return steps;
    }
        }
    
long long toh(int N, int from, int to, int aux){
    return tohu(N, from, to, aux);
}
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}



// } Driver Code Ends