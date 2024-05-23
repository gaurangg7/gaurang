#User function Template for python3
class Solution:
    ##Complete this function
    #Function to rearrange  the array elements alternately.
    def rearrange(self,arr, n): 
        ##Your code here
        #User function Template for python3

        
       
        if n % 2 == 0:
            for i in range(n // 2):
                arr.append(arr[n - 1 - i])
                arr.append(arr[i])
        else:
            for i in range(n // 2):
                arr.append(arr[n - 1 - i])
                arr.append(arr[i])
            arr.append(arr[n // 2])
        arr[:] = arr[n:]
        return arr


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math




def main():
        T=int(input())
        while(T>0):
            
            n=int(input())
            
            arr=[int(x) for x in input().strip().split()]
            
            ob=Solution()
            ob.rearrange(arr,n)
            
            for i in arr:
                print(i,end=" ")
            
            print()
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends