class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> countMap;
        int majCount = nums.size()/2 +1;
        for(int number : nums){
            countMap[number]++;
        }
        for(auto a: countMap){
            if(a.second >=majCount)
                return a.first;
        }
        return 0;
    }
};