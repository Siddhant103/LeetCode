class Solution {
public:
    string reverseWords(string s) {
        int index = 0;
        int i = 0;
        
        while(s[i] == ' '){
            i++;
        }
        
        s = s.substr(i);
        i = s.size() - 1;
        while(s[i] == ' '){
            i--;
        }
        s = s.substr(0, i + 1);
        
        stringstream ss(s);
        string word;
        string result;
        int left, right;
        while(ss >> word){
            string t = word;
            left = 0, right = word.size() - 1;
            while(left < right){
                char temp = t[left];
                t[left] = t[right];
                t[right] = temp;
                left++;
                right--;
            }
            result += t;
            result += ' ';
        }
        
        result = result.substr(0, result.size() - 1);
        left = 0, right = result.size() - 1;
        while(left < right){
            char temp = result[left];
            result[left] = result[right];
            result[right] = temp;
            left++;
            right--;
        }
        
        return result;
    }
};