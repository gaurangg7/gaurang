//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here  if (head == nullptr || head->next == nullptr)
       if (head == nullptr || head->next == nullptr)
            return head;

        Node* slow = head;
        Node* fast = head;
        Node* beforeMid = head;
        while (fast != nullptr && fast->next != nullptr) {
            beforeMid = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* mid = slow;
        beforeMid->next = nullptr;

        Node* left = mergeSort(head);
        Node* right = mergeSort(mid);

        return sortedList(left, right);
    }
    
     Node* sortedList(Node* a, Node* b) {
        if (a == nullptr)
            return b;
        if (b == nullptr)
            return a;

        Node* head = nullptr;
        Node* tail = nullptr;

        if (a->data <= b->data) {
            head = a;
            tail = a;
            a = a->next;
        } else {
            head = b;
            tail = b;
            b = b->next;
        }

        while (a != nullptr && b != nullptr) {
            if (a->data <= b->data) {
                tail->next = a;
                tail = a;
                a = a->next;
            } else {
                tail->next = b;
                tail = b;
                b = b->next;
            }
        }

        if (a != nullptr) {
            tail->next = a;
            tail = a;
        }
        if (b != nullptr) {
            tail->next = b;
            tail = b;
        }

        return head;
    }

};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends