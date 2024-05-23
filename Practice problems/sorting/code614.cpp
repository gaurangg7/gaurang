//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    // The function should do the stated modifications in the given array arr[]
    // Do not return anything.
    
    // arr[]: Input Array
    // N: Size of the Array arr[]
    //Function to segregate 0s, 1s and 2s in sorted increasing order.
    void segragate012(int arr[], int N)
    {
        // Your Code Here
         int count0 = 0, count1 = 0, count2 = 0;
    
    // Count the number of 0s, 1s, and 2s in the array
    for (int i = 0; i < N; i++) {
        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else
            count2++;
    }
    
    // Set the elements in the array based on counts
    for (int i = 0; i < count0; i++) {
        arr[i] = 0;
    }
    for (int i = count0; i < count0 + count1; i++) {
        arr[i] = 1;
    }
    for (int i = count0 + count1; i < N; i++) {
        arr[i] = 2;
    }
    }
};


//{ Driver Code Starts.
int main() {

    int T;
    cin >> T;

    while(T--){
        int N;
        cin >>N;
        int A[N];
        for(int i=0;i<N;i++){
            cin >> A[i];
        }

        Solution ob;
        ob.segragate012(A, N);

        for(int i=0;i<N;i++){
            cout << A[i]  << " ";
        }

        cout << endl;
        
        
    }

}

// } Driver Code Ends