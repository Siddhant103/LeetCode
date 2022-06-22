class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minPQ;
        for(int i: nums){
            minPQ.push(i);
            if(minPQ.size()>k)
                minPQ.pop();
        }
        
        return minPQ.top();
    }
};