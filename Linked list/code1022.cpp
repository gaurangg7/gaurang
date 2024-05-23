//{ Driver Code Starts
import java.io.*;
import java.util.*;
import java.lang.*;

  public class LRUDesign {

    public static void main(String[] args) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {

            int capacity = Integer.parseInt(read.readLine());
            int queries = Integer.parseInt(read.readLine());
            LRUCache cache = new LRUCache(capacity);
            String str[] = read.readLine().trim().split(" ");
            int len = str.length;
            int itr = 0;

            for (int i = 0; (i < queries) && (itr < len); i++) {
                String queryType = str[itr++];
                if (queryType.equals("SET")) {
                    int key = Integer.parseInt(str[itr++]);
                    int value = Integer.parseInt(str[itr++]);
                    cache.set(key, value);
                }
                if (queryType.equals("GET")) {
                    int key = Integer.parseInt(str[itr++]);
                    System.out.print(cache.get(key) + " ");
                }
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends


// design the class in the most optimal way

class LRUCache
{
     static int capacity;
    static HashMap<Integer,Node> cache;
    static Node head;
    static Node tail;
    
    
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        //code here
        this.capacity = cap;
        cache = new HashMap<>(cap);
        head = null;
        tail = null;
    }

    //Function to return value corresponding to the key.
    public static int get(int key)
    {
        // your code here
         if(cache.containsKey(key)){
            Node node = cache.get(key);
            moveToFront(node);
            return node.value;
        }
        
        return -1;
    }

    //Function for storing key-value pair.
    public static void set(int key, int value)
    {
        // your code here
          if(cache.containsKey(key)){
            Node node = cache.get(key);
            node.value = value;
            moveToFront(node);
            return;
        }
        
        Node node = new Node(key,value);
        
        if(cache.size() == capacity){
            cache.remove(tail.key);
            remove(tail);
        }
         addToFront(node);
         cache.put(key,node);
    }
    
    static void moveToFront(Node node){
        remove(node);
        addToFront(node);
    }
    
    static void remove(Node node){
        Node nextNode = node.next;
        Node prevNode = node.prev;
        
        if(prevNode != null)
            prevNode.next = nextNode;
        else{
            head = nextNode;
        }
        
        if(nextNode != null)
            nextNode.prev = prevNode;
        else
            tail = prevNode;
    }
    
    static void addToFront(Node node){
        node.next = head;
        node.prev = null;
        
        if(head != null)
            head.prev = node;
        head = node;
        
        if(tail == null)
            tail = node;
        
    }
    
    }
    class Node
{
    int key;
    int value;
    Node next;
    Node prev;

    Node(int key,int value)
    {
        this.key = key;
        this.value = value;
    }   
}
