//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	// Your code here
	 vector<string> result;
    queue<string> q;
    q.push("1");

    while (N--) {
        string current = q.front();
        q.pop();
        result.push_back(current);

        string next = current;
        q.push(next.append("0"));

        next = current;
        q.push(next.append("1"));
    }

    return result;
}


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends