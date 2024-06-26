//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

bool areIdentical(struct Node *a, struct Node *b);


int main()
{
    int T;
    cin>>T;
    while(T--){
        int n1, n2, tmp , d1 , d2;
        struct Node *head1 = NULL , *tail1=NULL;
        struct Node *head2 = NULL , *tail2 =NULL;
        cin>>n1;
        cin>>d1;
        head1 = new Node(d1);
        tail1 = head1;
        while(n1-- > 1){
            cin>>tmp;
            tail1->next = new Node(tmp);
            tail1 = tail1->next;
        }
        cin>>n2;
        cin>>d2;
        head2 = new Node(d2);
        tail2 = head2;
        while(n2-- >1)
        {
            cin>>tmp;
            tail2->next = new Node(tmp);
            tail2 = tail2->next;
        }
        areIdentical(head1, head2)?cout<<"Identical"<<endl:cout<<"Not identical"<<endl;
    }
	return 0;
}

// } Driver Code Ends


/*
Structure of the node of the linked list is as
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to check whether two linked lists are identical or not. 
bool areIdentical(struct Node *head1, struct Node *head2)
{
    // Code here
      // If both lists are empty, they are identical
    if (head1 == nullptr && head2 == nullptr)
        return true;
    // If one list is empty and the other is not, they are not identical
    else if (head1 == nullptr || head2 == nullptr)
        return false;

    Node* curr1 = head1;
    Node* curr2 = head2;

    // Traverse both lists simultaneously
    while (curr1 != nullptr && curr2 != nullptr) {
        // If data of current nodes are different, lists are not identical
        if (curr1->data != curr2->data)
            return false;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    // If both lists are exhausted at the same time, they are identical
    if (curr1 == nullptr && curr2 == nullptr)
        return true;

    // If one list is exhausted before the other, they are not identical
    return false;
}