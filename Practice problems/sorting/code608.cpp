//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int countInversions(long long arr[], int l, int r, long long temp[]) {
    long long int res = 0;
    if (r > l) {
        int mid = (l + r) / 2;
        res += countInversions(arr, l, mid, temp);
        res += countInversions(arr, mid + 1, r, temp);
        res += merger(arr, l, mid, r, temp);
    }
    return res;
}

long long int merger(long long arr[], int l, int m, int r, long long temp[]) {
    int n1 = m - l + 1;
    int n2 = r - m;
    long long int res = 0;
    
    vector<long long> left(n1), right(n2);
    for (int i = 0; i < n1; i++) {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = arr[m + 1 + i];
    }
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            res += (long long)(n1 - i);
        }
    }
    while (i < n1) {
        arr[k++] = left[i++];
    }
    while (j < n2) {
        arr[k++] = right[j++];
    }
    return res;
}
    
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
         long long temp[N];
    return countInversions(arr, 0, N - 1, temp);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends