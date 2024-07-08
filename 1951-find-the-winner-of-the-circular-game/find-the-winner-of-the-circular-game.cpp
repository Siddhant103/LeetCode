class Solution {
public:
    void josephus(vector<int> &v, int start, int k){
        if(v.size()==1){             
            return;
        }
        start+=k;                    
        int s = v.size();
        start%=s;                    
        v.erase(v.begin()+start);     
        josephus(v,start,k); 
        return;
    }
    
    
    int findTheWinner(int n, int k) {
        vector<int> v(n);
        k--;
        for(int i=1; i<=n; i++){
            v[i-1]=i;
        }
        josephus(v,0,k);
        return v[0];
    }
};