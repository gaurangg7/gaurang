//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
             return mergeK(arr, arr[0], nullptr, 0, K);
    }
    
      static Node* mergeK(Node* arr[], Node* A, Node* B, int i, int N) {
        Node* curr = merge2(A, B);
        if (i == N - 1)
            return curr;

        return mergeK(arr, curr, arr[i + 1], i + 1, N);
    }

    static Node* merge2(Node* A, Node* B) {
        if (A == nullptr)
            return B;
        if (B == nullptr)
            return A;

        Node* head = nullptr;
        Node* tail = nullptr;

        if (A->data <= B->data) {
            head = A;
            tail = A;
            A = A->next;
        } else {
            head = B;
            tail = B;
            B = B->next;
        }

        while (A != nullptr && B != nullptr) {
            if (A->data <= B->data) {
                tail->next = A;
                tail = A;
                A = A->next;
            } else {
                tail->next = B;
                tail = B;
                B = B->next;
            }
        }

        if (A == nullptr)
            tail->next = B;
        if (B == nullptr)
            tail->next = A;

        return head;
    }
    
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends