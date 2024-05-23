//{ Driver Code Starts
// Initial Template for C++

// CPP program to find a pair with
// given sum using hashing
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}


bool findPair(Node* root, int sum);

// Driver code
int main() {

    int t;
    cin >> t;
    while (t--) {
        Node* root = NULL;
        int n, x;
        cin >> n;
        int val;
        for (int i = 0; i < n; i++) {
            cin >> val;
            root = insert(root, val);
        }
        cin >> x;
        if (findPair(root, x))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }

    return 0;
}
// } Driver Code Ends


//Function to check if any pair exists in BST whose sum is equal to given value.
bool findPair(Node* root, int X) 
{
    // Your code here
     if(!root)
    return false;
    stack<Node *>it1,it2;
    Node* c=root;
    while(c) 
    {
        it1.push(c); 
        c=c->left;
    }
    c=root;
    while(c) 
    {
        it2.push(c); 
        c=c->right;
    }
    while(it1.top()!=it2.top())
    {
        int v1=it1.top()->data;
        int v2=it2.top()->data;
        if(v1+v2==X)
        return true;
        if(v1+v2<X)
        {
            Node *temp=it1.top()->right;
            it1.pop();
            
            while(temp) 
            {
                it1.push(temp);
                temp=temp->left;
            }
            
            
        }
        else
        {
            Node *temp=it2.top()->left;
            it2.pop();
            
            while(temp) 
            {
                it2.push(temp);
                temp=temp->right;
            }
            
        }
    }
    return false;
}



