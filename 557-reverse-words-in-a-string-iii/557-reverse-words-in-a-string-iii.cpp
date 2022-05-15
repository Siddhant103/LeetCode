class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        
        string result = "";
        while(ss >> word){
            int left = 0, right = word.size() - 1;
            while(left < right){
                char temp = word[left];
                word[left] = word[right];
                word[right] = temp;
                left++; right--;
            }
            result += word;
            result += " ";
        }
        
        result = result.substr(0, result.size() - 1);
        return result;
    }
};