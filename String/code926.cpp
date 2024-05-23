//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string S, string P)
    {
        // Your code here
         if (S.length() < P.length())
        return "-1";
    
    int start = 0;
    int end = P.length() - 1;
    
    int startRes = 0;
    int endRes = 0;
    
    std::vector<int> visited(26, 0);
    std::vector<int> pattern(26, 0);
    int minLength = INT_MAX;
    
    for (int i = 0; i <= end; i++) {
        visited[S[i] - 'a']++;
        pattern[P[i] - 'a']++;
    }
    
    auto compareWindows = [&]() {
        for (int i = 0; i < 26; i++) {
            if (visited[i] == 0 && pattern[i] == 0)
                continue;
            if (visited[i] < pattern[i])
                return false;
        }
        return true;
    };
    
    auto generateResult = [&](int start, int end) {
        std::string result = "";
        for (int i = start; i <= end; i++)
            result += S[i];
        return result;
    };
    
    if (compareWindows())
        return generateResult(start, end);
        
    end++;
    visited[S[end] - 'a']++;
    
    while (start <= end && end < S.length()) {
        if (compareWindows() && start < S.length()) {
            visited[S[start] - 'a']--;
            if (end - start + 1 < minLength) {
                startRes = start;
                endRes = end;
                minLength = end - start + 1;
            }
            start++;
        } else {
            end++;
            if (end < S.length())
                visited[S[end] - 'a']++;
        }
    }
    
    return (minLength != INT_MAX) ? generateResult(startRes, endRes) : "-1";
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends