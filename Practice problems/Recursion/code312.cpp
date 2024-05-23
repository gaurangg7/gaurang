//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
  void allWords(int a[], int N, string num[], int i, string curr, vector<string> &res) {
        if (i == N) {
            res.push_back(curr);
            return;
        }
        string temp = num[a[i]];
        for (int j = 0; j < temp.length(); j++) {
            allWords(a, N, num, i + 1, curr + temp[j], res);
        }
    }

    vector<string> possibleWords(int a[], int N) {
        vector<string> res;
        
        if (N == 0)
            return res;

        string num[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string curr = "";
        allWords(a, N, num, 0, curr, res);
        return res;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends