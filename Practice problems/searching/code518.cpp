//User function Template for C++

class Solution
{
    public:
    //Function to return the maximum water that can be stored.
    int maxWater(int height[], int n) 
    { 
        //Your code here
         int maximum = 0;
    int i = 0;
    int j = n - 1;
    
    while (i < j) {
        if (height[i] < height[j]) {
            maximum = std::max(maximum, (j - i - 1) * height[i]);
            i++;
        } else if (height[j] < height[i]) {
            maximum = std::max(maximum, (j - i - 1) * height[j]);
            j--;
        } else {
            maximum = std::max(maximum, (j - i - 1) * height[i]);
            i++;
            j--;
        }
    }
    
    return maximum;
    } 
};
