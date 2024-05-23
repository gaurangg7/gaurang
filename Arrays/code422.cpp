class Solution{
	public:
	vector<int>LargestFraction(int n, int d){
	    // Code here
	    int num = 0 , den = 1;
	    for(int q = 10000; q>=2;q--)
	    {
	        int p = (n*q -1)/d;
	        if(p * den >= q*num)
	        {   
	               den = q;
	               num = p;
	        }
	        
	    }
	    int g =__gcd(num,den);
	    vector<int>ans;
	    ans.push_back(num/g);
	    ans.push_back(den/g);
	    return ans;
	}
	   
};