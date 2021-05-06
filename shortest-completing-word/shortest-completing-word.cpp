class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> count(26,0);
        
        for(char c: licensePlate){
            if(c>=97 && c<=122){
                count[c-'a']++;
            } else if(c>=65 && c<=90){
                count[c-'A']++;
            }
        }
        for(int i=0;i<26;i++)
            cout<<count[i]<<" ";
        cout<<endl;
        
        string result = "";
        for(string s: words){
            vector<int> copy(26,0);
            copy = count;
            for(char c: s){
                cout<<copy[c-'a']<<" ";
                copy[c -'a']--;
            }
            bool flag = true;
            cout<<endl;
            for(int i=0;i<26;i++){
                cout<<copy[i]<<" ";
                if(copy[i]>0){
                    flag = false;
                }
            }
            if(flag == true){
                if(result == "" || s.size()<result.size())
                    result = s;
            }
            copy.clear();
            cout<<endl;
        }
        
        return result;
    }
};