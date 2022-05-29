class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if(n == 0){
            return 0;
        }
        
        vector<int> hash(n);
        int maxProd = 0;
        
        
        for(int i=0;i<n;i++){
            int num = 0;
            for(int j=0;j<words[i].size();j++){
                int x = words[i][j] - 'a';
                num |= 1<<x;
            }
            hash[i] = num;
        }
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if((hash[i] & hash[j]) == 0){
                    maxProd = max(maxProd, int(words[i].size()) * int(words[j].size()));
                }
            }
        }
        
        return maxProd;
    }
};