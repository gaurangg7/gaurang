//{ Driver Code Starts
//Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
class GFG {
	public static void main (String[] args) {
	    
	    //Taking input using class Scanner
		Scanner sc=new Scanner(System.in);
		
		//taking count of all testcases
		int t=sc.nextInt();
		
		while(t-->0)
		{
		    //Declaring and Intializing an ArrayDeque
		     ArrayDeque<Integer> deq = new ArrayDeque<Integer>(); 
		     
		     //Taking in the total count of elements
		     int n=sc.nextInt();
		     
		     //adding all the elements to the ArrayDeque
		     for(int i=0;i<n;i++)
		     {
		         int x=sc.nextInt();
		         deq.add(x);
		     }
		     
		     //Taking in the query type
		     int eraseQuery=sc.nextInt();
            
            
            if(eraseQuery == 1)//if query type is 1 we call the eraseAt method
            {
                int pos=sc.nextInt();
                eraseAt(deq, pos);
            }
            else if(eraseQuery == 2)//if query type is 2 we call the eraseInRange method
            {
                int start, end;
                start=sc.nextInt();
                end=sc.nextInt();
                eraseInRange(deq, start, end);
            }
            else//if query type is other than 2 or 1 we call the eraseAll method
            {
                eraseAll(deq);
                
            }
            
            //if ArrayDeque is empty we print "Empty"
            if(deq.isEmpty())
                System.out.print("Empty"); 
            else//else we print all the elements
                {
                    for(int x:deq)
                    System.out.print(x+" ");
                    
                }
            System.out.println();
    	}
	}
	
	


    
// } Driver Code Ends
//User function Template for Java

//Function to erase the element from specified position X in deque.
public static void eraseAt(ArrayDeque<Integer> deq , int X)
{
    //Your code here
    if(deq.isEmpty())
    return;
    int c=0;
    Iterator itr=deq.iterator();
    Stack<Integer> st=new Stack<Integer>();
   
    while(itr.hasNext())
    {
        if(c==X)
        {
            itr.next();
        }
        else
        {
            st.push((Integer) itr.next());
        }
        c++;
    }
    deq.clear();
    while(!st.isEmpty())
    {
        deq.push(st.pop());    
    }
}

//Function to erase the elements in range start (inclusive), end (exclusive).
public static void eraseInRange(ArrayDeque<Integer> deq , int start, int end)
{
    //Your code here
     if(deq.isEmpty())
        return;
    int c=0;
    Iterator itr=deq.iterator();
    Stack<Integer> st=new Stack<Integer>();
   
    while(itr.hasNext())
    {
        if(c>=start && c<end)
        {
            itr.next();
        }
        else
        {
            st.push((Integer) itr.next());
        }
        c++;
    }
    deq.clear();
    while(!st.isEmpty())
    {
        deq.push(st.pop());    
    }
}

//Function to erase all the elements in the deque.
public static void eraseAll(ArrayDeque<Integer> deq )
{
    //Your code here
    deq.clear();
}


//{ Driver Code Starts.


}
// } Driver Code Ends