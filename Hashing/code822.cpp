//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
  void dfs(string& name, string& email, unordered_map<string, vector<string>>& graph, unordered_set<string>& visited, vector<string>& emails) {
        if (visited.count(email)) return;
        visited.insert(email);
        emails.push_back(email);
        for (auto& neighbor : graph[email]) {
            dfs(name, neighbor, graph, visited, emails);
        }
    }
  
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        
         unordered_map<string, string> emailToName;
        unordered_map<string, vector<string>> graph;
        
        // Build graph and emailToName map
        for (auto& account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); ++i) {
                emailToName[account[i]] = name;
                if (i == 1) continue; // Skip the name
                graph[account[i]].push_back(account[i - 1]); // Add edge to previous email
                graph[account[i - 1]].push_back(account[i]); // Add edge to current email
            }
        }
        
        // DFS to group connected emails
        unordered_set<string> visited;
        vector<vector<string>> mergedAccounts;
        for (auto it = emailToName.begin(); it != emailToName.end(); ++it) {
            string email = it->first;
            string name = it->second;
            if (visited.count(email)) continue;
            vector<string> emails;
            dfs(name, email, graph, visited, emails);
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), name);
            mergedAccounts.push_back(emails);
        }
        
        return mergedAccounts;
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}
// } Driver Code Ends