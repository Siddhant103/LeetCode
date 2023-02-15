class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        
        vector<int> number;
        int index = nums.size()-1;
        int carry = 0;
        
        while(k && index>=0){
            int digit = k%10;
            k/=10;
            
            int sum = nums[index] + digit + carry;
            if(sum >= 10){
                sum = sum%10;
                carry = 1;
            } else{
                carry = 0;
            }
            
            number.push_back(sum);
            index--;
        }
        
        while(k){
            number.push_back( (k%10 + carry >=10 ? (k%10 + carry)%10 : k%10 + carry) );
            carry = k%10 + carry>=10 ? 1:0;
            k/=10;
        }
        
        while(index>=0){
            number.push_back(((nums[index]+carry>=10)?(nums[index]+carry)%10:nums[index]+carry));
            carry = nums[index]+carry>=10 ? 1:0;
            index--;
        }
        if(carry!=0){
            number.push_back(1);
        }
        
        reverse(number.begin(), number.end());
        return number;
    }
};