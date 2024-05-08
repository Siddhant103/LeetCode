class Solution {
public:

    static bool cmp (pair<int,int> p1, pair<int,int> p2) {
        return p1.first > p2.first;
    }

    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n=score.size();
        vector<pair<int,int>> arr;
        vector<string> ans(n,"");

        for(int i=0;i<n;i++) {
            arr.push_back({score[i], i});
        }

        sort(arr.begin(), arr.end(), cmp);

        int pos=1;
        for(int i=0;i<n;i++) {
            if(pos==1) {
                ans[arr[i].second] = "Gold Medal";
            }
            else if(pos==2) {
                ans[arr[i].second] = "Silver Medal";
            }
            else if(pos==3) {
                ans[arr[i].second] = "Bronze Medal";
            }
            else {
                ans[arr[i].second] = to_string(pos);
            }

            pos++;
        }

        return ans;
    }
};