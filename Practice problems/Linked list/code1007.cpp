//{ Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
        
    bool f=true;
    
    for(int i=0; i<num; i++){
        if((i==K-1) || (i==num - K)){
            if(!((before[K-1] == after[num - K]) && (before[num-K] == after[K-1]))) f=0;
        }
        else{
            if(before[i] != after[i]) f=0;
        }
    }
    
    return f;
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}

// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int num, int K)
{
    // Your Code here
     if (head == nullptr || head->next == nullptr)
        return head;

    // Calculate the length of the linked list
    int length = 0;
    Node* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }

    // Check if K is within the valid range
    if (K <= 0 || K > length || 2*K - 1 == length)
        return head;

    // Find the Kth node from the beginning of the list
    Node* currStart = head;
    Node* prevStart = nullptr;
    for (int i = 1; i < K; i++) {
        prevStart = currStart;
        currStart = currStart->next;
    }

    // Find the Kth node from the end of the list
    Node* currEnd = head;
    Node* prevEnd = nullptr;
    for (int i = 1; i < length - K + 1; i++) {
        prevEnd = currEnd;
        currEnd = currEnd->next;
    }

    // Check if nodes to be swapped are adjacent
    if (prevStart != nullptr)
        prevStart->next = currEnd;
    if (prevEnd != nullptr)
        prevEnd->next = currStart;

    // Swap next pointers of the nodes
    Node* tempNext = currStart->next;
    currStart->next = currEnd->next;
    currEnd->next = tempNext;

    // Update head if necessary
    if (K == 1)
        head = currEnd;
    else if (K == length)
        head = currStart;

    return head;}
    
