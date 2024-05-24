//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int N, int M)
{
    // write code here
    long long ans = 0;
    long long int mod = 1e9+7;
    int dx[8] = {-2, -1, 1,2, 2, 1, -1, -2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    for(int x = 0; x<N; x++)
    {
        for(int y=0;y<M; y++){
            int count = M*N -1;
            
            for(int k =0; k<8; k++){
                int nx =  x + dx[k];
                int ny  = y + dy[k];
                if(nx >= 0 and nx< N and ny>=0 and ny<M)
                count--;
                
            }
            ans = (ans + count )%mod;
            
        }
    }
    return ans;
}