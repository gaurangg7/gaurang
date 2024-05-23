//{ Driver Code Starts
//Initial Template for C++
#include<iostream> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Complete this function
      int even_odd(int key)
    {
    if(key%2==0)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

int max(int a,int b)
{
    if(a>b)
    return a;
    else
    {
        return b;
    }
}
    //Function to find the length of longest subarray of even and odd numbers.
    int maxEvenOdd(int arr[], int n) 
    { 
       //Your code here
         int flag;
    int count;
    int res=1;
    for(int i=0;i<n-1;i++)
    {
        flag=even_odd(arr[i]);
        count=1;
        for(int j=i+1;j<n;j++)
        {
            if(flag==2)
            {
                if(arr[j]%2!=0)
                {
                    count=count+1;
                }
                else
                {
                    break;
                }
            }
            if(flag==1)
            {
                if(arr[j]%2==0)
                {
                    count=count+1;
                }
                else
                {
                    break;
                }
            }
            flag=even_odd(arr[j]);
            res=max(count,res);
        }
    }
    return res;
       
    } 
};

//{ Driver Code Starts.
int main() 
{ 
    int testcases;
    //testcases
    cin>>testcases;
    while(testcases--)
    {
        int sizeOfArray;
        //size of array
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        
        //inserting elements in the array
        for(int i=0;i<sizeOfArray;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        //calling function
        cout  << ob.maxEvenOdd(arr, sizeOfArray)<<endl; 
    }
   return 0; 
} 

// } Driver Code Ends