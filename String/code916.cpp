//{ Driver Code Starts
// C++ program to calculate sum of all numbers present
// in a string containing alphanumeric characters
#include <iostream>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate sum of all numbers present in a string.
    int findSum(string str) {
    int sum = 0;
    string num = "";

    // Iterate through the string
    for (char c : str) {
        // If current character is a digit, append it to num
        if (isdigit(c)) {
            num += c;
        } else {
            // If num is not empty, convert it to integer and add to sum
            if (!num.empty()) {
                sum += stoi(num);
                num = ""; // Reset num for next number
            }
        }
    }

    // Add the last number if num is not empty
    if (!num.empty()) {
        sum += stoi(num);
    }

    return sum;
}
};


//{ Driver Code Starts.

// Driver code
int main()
{
	// input alphanumeric string
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution obj;
	    cout << obj.findSum(str);
        cout<<endl;
	}
	return 0;
}

// } Driver Code Ends