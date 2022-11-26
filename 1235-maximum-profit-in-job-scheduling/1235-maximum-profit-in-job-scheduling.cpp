class Solution {
public:
    static bool cmp(array<int,3> a,array<int,3> b)
    {
        return a[1]<b[1];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int sz=profit.size();
        vector<int> dp(sz);
        vector<array<int,3>> v;
        
        for(int i=0;i<sz;i++)
            v.push_back({startTime[i],endTime[i],profit[i]});
			
        sort(endTime.begin(),endTime.end());
        sort(v.begin(),v.end(),cmp);
		
        dp[0]=v[0][2];
        for(int i=1;i<sz;i++){
            int pos=upper_bound(endTime.begin(),endTime.begin()+i,v[i][0])-endTime.begin();
            if(pos==0)
                dp[i]=max(dp[i-1],v[i][2]);
            else
                dp[i]=max(dp[i-1],v[i][2]+dp[pos-1]);
        }
        return dp[sz-1];   
    }
};