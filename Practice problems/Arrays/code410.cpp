    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        std::vector<int> leaders;
    int maxx = a[n - 1];
    leaders.push_back(maxx);
    
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] >= maxx) {
            maxx = a[i];
            leaders.push_back(maxx);
        }
    }
    
    std::reverse(leaders.begin(), leaders.end());
    return leaders;
    }
};