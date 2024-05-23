class Solution{
    public:
    // L and R are input array
    // maxx : maximum in R[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in L[] and R[]
    //Function to find the maximum occurred integer in all ranges.
    int maxOccured(int L[], int R[], int n, int maxx){
    
        // Your code here
         vector<int> arr(1000000, 0);
    int sum = 0, max = 0, index = 0;

    for (int i = 0; i < n; i++) {
        arr[L[i]]++;
        arr[R[i] + 1]--;
    }

    for (int i = 0; i < 1000000; i++) {
        sum += arr[i];
        if (sum > max) {
            max = sum;
            index = i;
        }
    }
    return index;
    }
};