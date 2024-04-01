class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.size()-1;
        int count = 0;
        while(index>=0){
            if(s[index]==' ')
                index--;
            else
                break;
        }
        while(index>=0){
            cout<<s[index];
            if(s[index] == ' ')
                return count;
            count++;
            index--;
        }
        return count;
    }
};