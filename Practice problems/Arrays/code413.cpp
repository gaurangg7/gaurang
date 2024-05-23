//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 

// } Driver Code Ends
class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
      std::vector<int> freq(N, 0);

    // Increment the frequency of each element in arr
    for (int i = 0; i < N; ++i) {
        // If the current element is greater than N, ignore it
        if (arr[i] > N) continue;

        // Decrement the value of arr[i] by 1 to make it zero-based
        int index = arr[i] - 1;

        // Increment the count of the corresponding element by P
        freq[index] += P;
    }

    // Adjust the values in the array to represent frequency count
    for (int i = 0; i < N; ++i) {
        arr[i] = freq[i] / P;
    }
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
   
    }
};


//{ Driver Code Starts.

int main() 
{ 
	long long t;
	
	//testcases
	cin >> t;
	
	while(t--){
	    
	    int N, P;
	    //size of array
	    cin >> N; 
	    
	    vector<int> arr(N);
	    
	    //adding elements to the vector
	    for(int i = 0; i < N ; i++){
	        cin >> arr[i]; 
	    }
        cin >> P;
        Solution ob;
        //calling frequncycount() function
		ob.frequencyCount(arr, N, P); 
		
		//printing array elements
	    for (int i = 0; i < N ; i++) 
			cout << arr[i] << " ";
	    cout << endl;
	}	
	return 0; 
}





// } Driver Code Ends