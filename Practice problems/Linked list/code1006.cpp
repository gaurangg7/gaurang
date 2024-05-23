//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(Node* head){
        Node* prev=NULL;
        Node* cur=head;
        Node* next=NULL;
        while(cur){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
        num1=reverse(num1);
        num2=reverse(num2);
        
        Node* num3=new Node(0);
        int sum=0,carry=0;
        Node* head=num3;
        while(num1 && num2){
            sum=num1->data+num2->data+carry;
            carry=sum/10;
            num3->next=new Node(sum%10);
            num1=num1->next;
            num2=num2->next;
            num3=num3->next;
        }
        while(num1){
            sum=num1->data+carry;
            carry=sum/10;
            num3->next=new Node(sum%10);
            num1=num1->next;
            num3=num3->next;   
        } while(num2){
            sum=num2->data+carry;
            carry=sum/10;
            num3->next=new Node(sum%10);
            num2=num2->next;
            num3=num3->next;
        }
        if(carry!=0){
            num3->next=new Node(carry);
        }
        Node* ans=reverse(head->next);
         while(ans->data==0 && ans->next!=NULL)
        {
            ans=ans->next;
        }
       return ans;
        
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends