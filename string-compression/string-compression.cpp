class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==0)
            return 0;
        
        int count = 1;
        char curr = chars[0];
        
        int index = 0;
        for(int i=1;i<chars.size();i++){
            if(chars[i] == curr){
                count++;
            } else{
                chars[index++] = curr;
                string freq = to_string(count);
                for(int j=0;j<freq.size() && count!=1;j++){
                    chars[index++] = freq[j];
                }
                count=1;
                curr = chars[i];
            }
        }
        
        chars[index++] = curr;
        string freq = to_string(count);
        
        for(int j=0;j<freq.size() && count!=1;j++){
            chars[index++] = freq[j];
        }
        
        return index;
    }
};