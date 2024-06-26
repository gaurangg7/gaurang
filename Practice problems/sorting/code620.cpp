//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
 

class Solution{
    public:
    
    int upperBound(int *arr,int n,int x ){
    

        long long l=0,r=n-1,ptr=n;
        while(l<=r){
            long long mid =(l+r)/2;
            if(arr[mid]<=x){
                l=mid+1;
            }
            else{
                ptr = mid;
                r = mid-1;
            }
        }

       return ptr;
    }
    long long count(int  x, int Arr[], int Y[], int n)
    {
        if(x==0)
        {
            return 0;
        }
        if(x==1)
        {
            return Arr[0];
        }
        int ptr=upperBound(Y,n,x);
        long long ans=n-ptr;
        ans=ans+(Arr[1]+Arr[0]);          
        if(x==2)
        {
            ans=ans-(Arr[3]+Arr[4]);
        }
        if(x==3)
        {
            ans=ans+Arr[2];
        }
        return ans;
    }
    
    // X[], Y[]: input array
    // M, N: size of arrays X[] and Y[] respectively
    //Function to count number of pairs such that x^y is greater than y^x.
    long long countPairs(int X[], int Y[], int m, int n)
    {
       //Your code here
       int Arr[5]={0};
        for(int i=0;i<n;i++)
        {
            if(Y[i]<5)
            {
                Arr[Y[i]]++;
            }
        }
        sort(Y,Y+n);
        long long result=0;
        for(int i=0;i<m;i++)
        {
            result=result+count(X[i],Arr,Y,n);
        }
        return result;
    }
};



//{ Driver Code Starts.
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		Solution ob;
		cout<<ob.countPairs(a, b, M, N)<<endl;
	}
}
// } Driver Code Ends