//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string upper_chars, lower_chars;
    for (char c : str) {
        if (isupper(c)) {
            upper_chars.push_back(c);
        } else if (islower(c)) {
            lower_chars.push_back(c);
        }
    }

    // Sort upper and lower case characters
    sort(upper_chars.begin(), upper_chars.end());
    sort(lower_chars.begin(), lower_chars.end());

    // Merge sorted characters based on the original string
    std::string sorted_string;
    auto upper_it = upper_chars.begin();
    auto lower_it = lower_chars.begin();
    for (char c : str) {
        if (islower(c)) {
            sorted_string.push_back(*lower_it);
            lower_it++;
        } else if (isupper(c)) {
            sorted_string.push_back(*upper_it);
            upper_it++;
        }
    }

    return sorted_string;
}
    
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends