class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        map<string, int> word_count;
        
        string temp = "";
        for(int i=0;i<A.size();i++){
            if(A[i]==' '){
                word_count[temp]++;
                temp = "";
                i++;
            }
            if(i==A.size()-1){
                temp += A[i];
                word_count[temp]++;
            }
            temp += A[i];
        }
        
        temp = "";
        for(int i=0;i<B.size();i++){
            if(B[i]==' '){
                word_count[temp]++;
                temp = "";
                i++;
            }
            if(i==B.size()-1){
                temp += B[i];
                word_count[temp]++;
            }
            temp += B[i];
        }
        
        vector<string> result;
        for(auto itr=word_count.begin();itr!=word_count.end();++itr){
            if(itr->second==1)
                result.push_back(itr->first);
        }
        
        return result;
    }
};