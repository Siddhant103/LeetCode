class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) 
    {
        long long int n = nums.size();
        
        long long int left_sum = 0;
        long long int right_sum = 0;
        
        priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int> >,greater<pair<long int,long int> > > pq;
        
        for(int i=0;i<n;i++) {
            right_sum += nums[i];
        }
        
        long long int i = 0;
        while(i<n) {
            right_sum -= nums[i];
            left_sum  += nums[i]; 
            
            long long int tmp=0;
            
            if(i < n-1) {
                tmp = abs((left_sum/(i+1)) - (right_sum/(n-i-1)));                                                            
            }
            else {
                tmp = (left_sum/(i+1));
            }
        
            pq.push({tmp,i});
            i++;
        }
        
        return pq.top().second;
    }
};