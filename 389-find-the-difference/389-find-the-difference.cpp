class Solution {
public:
    char findTheDifference(string s, string t) {
        char a;
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++; 
        }
        for(int i=0;i<t.length();i++){
            m[t[i]]++;
        }
        for(auto i:m){
            if(i.second%2==1){ //if the value is even it means it occurs in both the strings
                 a = i.first;
            }
        }
        return a;
    }
};