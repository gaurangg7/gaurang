//User function template for C++

class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        // Your code here
         std::vector<int> result;

    for (int i = 0; i < n + 2; i++) {
        if (arr[abs(arr[i])] < 0) {
            result.push_back(abs(arr[i]));
        } else {
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        }
    }

    return result;
       
    }
};