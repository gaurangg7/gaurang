//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to find nth number made of only prime digits.
    bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}
    int primeDigits(int n)
    {
        //code here
         int count = 0;
    int num = 2; // Start from the first prime number

    while (count < n) {
        // Convert the number to string to check each digit
        string s = to_string(num);
        bool all_prime = true;

        // Check if all digits are prime
        for (char c : s) {
            int digit = c - '0';
            if (!isPrime(digit)) {
                all_prime = false;
                break;
            }
        }

        // If all digits are prime, increment count
        if (all_prime) {
            count++;
        }

        // Move to the next number
        num++;
    }

    // Return the nth number whose each digit is prime
    return num - 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    // All the above tasks are preprocessing, now you can run testcases
    // and then print the values accordingly
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout << ob.primeDigits(n) << "\n";   
    }
}

// } Driver Code Ends