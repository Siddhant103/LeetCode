class Solution {
private:
    int maxfuel=0;
public:
    int recur(vector<vector<int>>& dp,vector<int>& arr,int index,int finish,int fuel){
        long long int ans=0;
        
        if(index==finish && fuel<=maxfuel)
            ans=1;
        
        if(fuel>maxfuel || index>=arr.size())
            return 0;
        
        if(dp[index][fuel]!=-1)
            return dp[index][fuel];
        
        for(int i=0;i<arr.size();i++)
        {
            if(i==index)continue;
            ans+=recur(dp,arr,i,finish,fuel + abs(arr[i]-arr[index]))%1000000007;
        }
        return dp[index][fuel]=ans%1000000007;
        
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        maxfuel=fuel;
        vector<vector<int>>dp(locations.size()+1,vector<int>(fuel+5,-1));
        return recur(dp,locations,start,finish,0);
    }
};