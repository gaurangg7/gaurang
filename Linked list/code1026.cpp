//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
         if (head == nullptr || head->next == nullptr)
            return true;

        Node* slow = head;
        Node* fast = head;
        Node* temp = head;

        while (fast != nullptr && fast->next != nullptr) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* revHead = nullptr;

        if (fast == nullptr) {
            revHead = reverse(slow, temp);
        } else {
            revHead = reverse(slow->next, slow);
        }

        Node* curr1 = head;
        Node* curr2 = revHead;

        while (curr2 != curr1 && curr1->next != curr2) {
            if (curr1->data != curr2->data)
                return false;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return curr1->data == curr2->data;
    }

    Node* reverse(Node* curr, Node* prev) {
        while (curr != nullptr) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends