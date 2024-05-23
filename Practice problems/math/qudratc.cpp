//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<int> quadraticRoots(int a, int b, int c) {
    vector<int> roots;
    int discriminant = b * b - 4 * a * c;

    // If discriminant is positive, roots are real and distinct
    if (discriminant > 0) {
        int root1 = floor((-b + sqrt(discriminant)) / (2 * a));
        int root2 = floor((-b - sqrt(discriminant)) / (2 * a));
        roots.push_back(max(root1, root2));
        roots.push_back(min(root1, root2));
    }
    // If discriminant is zero, roots are real and repeated
    else if (discriminant == 0) {
        int root = floor(-b / (2 * a));
        roots.push_back(root);
        roots.push_back(root);
    }
    // If discriminant is negative, roots are imaginary
    else {
        roots.push_back(-1); // Imaginary root
    }
    return roots;
}



            
        };
        
         
 


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        Solution ob;
        vector<int> roots = ob.quadraticRoots(a, b, c);
        if (roots.size() == 1 && roots[0] == -1)
            cout << "Imaginary";
        else
            for (int i = 0; i < roots.size(); i++) cout << roots[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends