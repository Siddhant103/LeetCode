class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if(arr.size() == 2)
            return true;
        
        sort(arr.begin(), arr.end());
        
        int d = arr[1] - arr[0];
        int n = arr.size();
        
        for(int i = 2; i < n; i++){
            if(arr[i] - arr[i-1] != d)
                return false;
        }
        
        return true;
    }
};