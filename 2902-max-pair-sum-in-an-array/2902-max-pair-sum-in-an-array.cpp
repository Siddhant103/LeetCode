class Solution {
public:
		int maxSum(vector<int>& nums) {
				int ans = -1;
				unordered_map<int,vector<int>> mp;

				for(auto n: nums){
						int t = n, maxDigit = 0;
						while (t) {
								maxDigit = max(t % 10, maxDigit);
								t = t / 10;
						}
						mp[maxDigit].push_back(n);
				}

				for(auto [k, v]: mp){
						sort(v.rbegin(), v.rend());
						if (v.size() >= 2) 
							ans = max(ans, v[0] + v[1]);
				}
				
				return ans;
		}
};