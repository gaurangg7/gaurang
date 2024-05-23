//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int precedence(char chr) {
    switch (chr) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return -1;
    }
}
    
    string infixToPostfix(string exp) {
        // Your code here
          string res = "";
    stack<char> st;

    for (int i = 0; i < exp.length(); i++) {
        char chr = exp[i];

        if (isalnum(chr)) // Check if the character is alphanumeric
            res += chr;
        else if (chr == '(')
            st.push(chr);
        else if (chr == ')') {
            while (!st.empty() && st.top() != '(')
                res += st.top(), st.pop();

            if (!st.empty() && st.top() == '(')
                st.pop();
        } else {
            while (!st.empty() && precedence(chr) <= precedence(st.top()))
                res += st.top(), st.pop();

            st.push(chr);
        }
    }

    while (!st.empty())
        res += st.top(), st.pop();

    return res;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends