/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here int low = 0; low = 0,
    int low = 0, high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        // If mid is a peak element, return mid
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid] >= arr[mid + 1]))
            return mid;

        // If the left neighbor of mid is greater, move towards the left
        if (mid > 0 && arr[mid - 1] > arr[mid])
            high = mid - 1;
        else // Otherwise, move towards the right
            low = mid + 1;
    }

    // If the loop ends, low and high will be equal, and it will be the peak element
    return low;
       
     
    }
};