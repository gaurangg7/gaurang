//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
     // deficit is used to store the value of the capacity as 
    // soon as the value of capacity becomes negative so as 
    // not to traverse the array twice in order to get the 
    // solution 
    int start = 0, deficit = 0; 
    int capacity = 0; 
    for (int i = 0; i < n; i++) { 
        capacity += p[i].petrol - p[i].distance; 
        if (capacity < 0) { 
            // If this particular step is not done then the 
            // between steps would be redundant 
            start = i + 1; 
            deficit += capacity; 
            capacity = 0; 
        } 
    } 
    return (capacity + deficit >= 0) ? start : -1; 
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends