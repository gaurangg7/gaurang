//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to rearrange the characters in a string such that 
    //no two adjacent characters are same.
    string rearrangeString(string str)
    {
    	// Your code here
    // Count the frequency of each character
   int count[26] = {0};
    for (char ch : str) {
        count[ch - 'a']++;
    }

    // Length of the string
    int n = str.size();

    // Initialize an empty string to store the rearranged characters
    string rearrangedStr = "";

    // Start rearranging the string in-place
    while (rearrangedStr.size() < n) {
        // Find the character with the maximum frequency
        int maxFreq = 0;
        char maxChar = '\0';
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0 && count[i] > maxFreq && (rearrangedStr.empty() || rearrangedStr.back() != 'a' + i)) {
                maxFreq = count[i];
                maxChar = 'a' + i;
            }
        }

        // If there are no characters left to append or if we cannot find a suitable character to append, return "0"
        if (maxFreq == 0) return "0";

        // Append the maxChar to the rearranged string
        rearrangedStr += maxChar;
        count[maxChar - 'a']--;
    }

    return rearrangedStr;
    }
};

//{ Driver Code Starts.

int checker(string str, string pat)
{
    int freq[26];
    for(int i=0;i<26;i++)
        freq[i]=0;
    if(str.length()!=pat.length())
        return 0;
    for(int i=0;i<str.length();i++)
    {
        freq[str[i]-97]--;
        if(pat[i]<97 || pat[i]>122)
            return 0;
        freq[pat[i]-97]++;
    }
    for(int i=0;i<26;i++)
        if(freq[i]!=0)
            return 0;
    for(int i=0;i<pat.length()-1;i++)
        if(pat[i]==pat[i+1])
            return 0;
    return 1;
}

int main()
{
	int t;
	cin>>t;
	cin.ignore(INT_MAX, '\n');
	while(t--)
	{
	    string str,ret;
	    cin>>str;
	    Solution ob;
	    ret = ob.rearrangeString(str);
	    cout << checker(str, ret) << endl;
	}
    return 0;
}
// } Driver Code Ends