class Solution {
public:
    bool isPalindrome(string num){
        string rev = num;
        reverse(rev.begin(), rev.end());
        return num == rev;
    }
    int superpalindromesInRange(string left, string right) {
        //Convert ranges into long long using stoll(this is similar to stoi)
        long long l = stoll(left);
        long long r = stoll(right);
        
        //to store generated palindromes from 1->10^9
        vector<long long> palStore;
        
        for(int i=1;i<=9;i++){
            palStore.push_back(i);
        }
        
        //running this loop from 1->10^4 in this way - (i + __ + rev(i))==this should be palindrome
        for(int i=1;i<=10000;i++){
            string s1 = to_string(i);
            string s2 = to_string(i);
            reverse(s2.begin(), s2.end());
            
            palStore.push_back(stoll(s1+s2));
            for(int j=0;j<=9;j++){
                palStore.push_back(stoll(s1 + to_string(j) + s2));
            }
        }
        
        //now adding all the palindromes whose squares are also palindrome using the isPalindrome method and ranges l,r
        int count=0;
        for(int i=0;i<palStore.size();i++){
            if(palStore[i]>1e9)
                continue;
            long long num = palStore[i]*palStore[i];
            if(num>=l && num<=r && isPalindrome(to_string(num))){
                count++;
            }
        }
        
        return count;
    }
};