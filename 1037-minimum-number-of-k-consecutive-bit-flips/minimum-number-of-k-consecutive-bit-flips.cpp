class Solution {
public:
    int minKBitFlips(vector<int>& ar, int k) {
        int n=ar.size(),ans=0;
        vector<int> flip(n,0);
        
        for(int i=0;i<n;i++){
            if(i) flip[i]+=flip[i-1];
            if((flip[i]%2 && ar[i]) || (flip[i]%2==0 && !ar[i])){
                ans++;
                // ar[i] MUST be flipped
                // ar[i+k] is not flipped
                flip[i]++;
                if(i+k>n) return -1;
                if(i+k<n) flip[i+k]--;
            }
        }
        return ans;
    }
};