class Solution {
public:
    string reorderSpaces(string text) {
        
        int spaces = 0;
        
        for(char c: text){
            if(c==' '){
                spaces++;
            }
        }
        
        stringstream ss(text);
        vector<string> words;
        string temp;
        
        while(ss >> temp){
            words.push_back(temp);
        }
        
        if(spaces == 0)
            return text;
        
        int n = words.size();
        string ans = "";
        
        if(n==1 && spaces==0){
            return text;
        }else if(n==1 && spaces!=0){
            ans += words[0];
            while(spaces--){
                ans += " ";
            }
            return ans;
        }
        
        int inBetweenSpaces = spaces/(n-1);
        string spaceString = "";
        for(int i=0;i<inBetweenSpaces;i++){
            spaceString += " ";
        }
        for(int i=0;i<n-1;i++){
            ans += words[i];
            ans += spaceString;
        }
        ans += words[n-1];
        
        if(spaces%(n-1)==0){
            //no trailing spaces needed
            return ans;
        }
        
        int remainingSpaces = spaces%(n-1);
        for(int i=0;i<remainingSpaces;i++){
            ans += " ";
        }
        
        return ans;
        
    }
};