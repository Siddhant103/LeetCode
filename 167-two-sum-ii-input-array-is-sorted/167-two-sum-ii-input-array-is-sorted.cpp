class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector<int> ans(2);
        while (left < right) {
            cout << left << " " << right << endl;
            if (numbers[left]  + numbers[right] == target) {
                ans[0] = left + 1;
                ans[1] = right + 1;
                break;
            } else if (numbers[left]  + numbers[right] < target) {
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
};