class Solution {
public:
    static bool comp(const string& a, const string& b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        
        int result = 0;
        map<string, int> dp;
  
        for(string word: words){
            
            dp.insert({word, 1});
            for(int i=0;i<word.size();i++){
                string temp = word.substr(0,i) + word.substr(i+1);
                cout << temp <<endl;
                if(dp.find(temp)!=dp.end()){
                    dp[word] = max(dp[word], dp[temp]+1);
                } 
            }
            result = max(result, dp[word]);
        }
        
        return result;
    }
};