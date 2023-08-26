class Solution {
public:
		int calculateLongestChain(int i, int prev, vector<vector<int>>& pairs, int n, vector<vector<int>>& dp){
			if(i == n) 
      		return 0;
			int pick = INT_MIN;
			if (dp[i][prev + 1] != -1) {
				return dp[i][prev + 1];
			}

			if (prev == -1 || pairs[prev][1] < pairs[i][0])
          pick = 1 + calculateLongestChain(i + 1, i, pairs, n, dp);
			int notpick = calculateLongestChain(i + 1, prev, pairs, n, dp);
			
			return dp[i][prev + 1] = max(pick, notpick);
		}

		int findLongestChain(vector<vector<int>>& pairs) {
			int n = pairs.size();
			sort(pairs.begin(), pairs.end());
			vector<vector<int>> dp(n, vector<int>(n + 1, -1));
			return calculateLongestChain(0, -1, pairs, n, dp);
		}
};