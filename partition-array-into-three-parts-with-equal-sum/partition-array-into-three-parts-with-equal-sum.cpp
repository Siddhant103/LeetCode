class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for(int num: arr){
            sum += num;
        }
        
        if(sum % 3 != 0){
            return false;
        }
        
        sum = sum / 3;
        int curr = 0;
        int partition = 0;
        for(int i=0;i<arr.size();i++){
            curr += arr[i];
            if(curr == sum){
                partition++;
                curr = 0;
            }
        }
        
        return partition >= 3;
    }
};