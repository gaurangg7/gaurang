//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
//User function Template for C++

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
 
 int recur_sum(Node* root, int prev_chosen, unordered_map<Node*, int>& chosen, unordered_map<Node*, int>& not_chosen) {
    if (root == NULL)
        return 0;

    // If the result is already calculated, return it.
    if (prev_chosen && chosen.find(root) != chosen.end())
        return chosen[root];
    else if (!prev_chosen && not_chosen.find(root) != not_chosen.end())
        return not_chosen[root];

    int d = root->data;
    if (prev_chosen) {
        int res1 = recur_sum(root->left, 0, chosen, not_chosen) + recur_sum(root->right, 0, chosen, not_chosen);
        chosen[root] = res1;
        return res1;
    } else {
        int res2 = recur_sum(root->left, 1, chosen, not_chosen);
        int res3 = recur_sum(root->right, 1, chosen, not_chosen);
        int res4 = recur_sum(root->left, 0, chosen, not_chosen);
        int res5 = recur_sum(root->right, 0, chosen, not_chosen);
        int max_sum = max(d + res2 + res3, res4 + res5);
        not_chosen[root] = max_sum;
        return max_sum;
    }
}
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
          if (root == NULL)
        return 0;

    unordered_map<Node*, int> chosen; // To store the maximum sum if current node is chosen
    unordered_map<Node*, int> not_chosen; // To store the maximum sum if current node is not chosen

    return recur_sum(root, 0, chosen, not_chosen);
    }
};

//{ Driver Code Starts.

// Driver code 
int main()
{
  int t;
  scanf("%d ",&t);
  while (t--)
  {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		Solution ob;
        cout<<ob.getMaxSum(root)<<endl;
  }
  return 0;
}
// } Driver Code Ends