//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    //Function to fill the array elements into a hash table 
    //using Linear Probing to handle collisions.
    vector<int> linearProbing(int hashSize, int arr[], int sizeOfArray)
    {
        //Your code here
      vector<int> hashTable(hashSize, -1); // Initialize hash table with -1
    for (int i = 0; i < sizeOfArray; ++i) {
        int hashIndex = arr[i] % hashSize; // Calculate hash index
        int index = hashIndex;
        while (hashTable[index] != -1 && hashTable[index] != arr[i]) { // Linear probing
            index = (index + 1) % hashSize;
            if (index == hashIndex) { // If linear probing reaches the starting index
                break; // Drop the element
            }
        }
        if (hashTable[index] == -1) { // If empty slot found
            hashTable[index] = arr[i]; // Insert element
        }
    }
    return hashTable;
        
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int hashSize;
	    cin>>hashSize;
	    
	    int  sizeOfArray;
	    cin>>sizeOfArray;
	    int arr[sizeOfArray];
	    
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    
	    vector<int> hash;
	    Solution obj;
	    hash = obj.linearProbing( hashSize, arr, sizeOfArray);
	    
	    for(int i=0;i<hashSize;i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	    
	}
	return 0;
}


// } Driver Code Ends