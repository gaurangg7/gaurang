//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





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
   Node* root = new Node(stoi(ip[0]));

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
           currNode->left = new Node(stoi(currVal));

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
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    struct Helper {
    Node* root;
    int status;
    Helper(Node* r, int s) : root(r), status(s) {}
};

    
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
         vector<int> res;
    stack<Helper> stack1, stack2;
    Node *curr1 = root1, *curr2 = root2;

    while (curr1 != nullptr || curr2 != nullptr || !stack1.empty() || !stack2.empty()) {
        while (curr1 != nullptr) {
            stack1.push(Helper(curr1, 0));
            curr1 = curr1->left;
        }

        while (curr2 != nullptr) {
            stack2.push(Helper(curr2, 0));
            curr2 = curr2->left;
        }

        if (!stack1.empty() && (stack2.empty() || stack1.top().root->data <= stack2.top().root->data)) {
            Helper top1 = stack1.top();
            stack1.pop();
            res.push_back(top1.root->data);
            curr1 = top1.root->right;
        } else {
            Helper top2 = stack2.top();
            stack2.pop();
            res.push_back(top2.root->data);
            curr2 = top2.root->right;
        }
    }

    return res;
}


   
};

//{ Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends