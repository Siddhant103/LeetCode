class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<double, vector<double>, greater<double>> min_arrivals;
        int ans = 0;

        for (int i = 0; i<dist.size(); i++) {
            min_arrivals.push(ceil((double)dist[i] / speed[i]));
        }

        int current_time = 0;
        while (!min_arrivals.empty()) {
            if (current_time<min_arrivals.top()) {
                min_arrivals.pop();
                ans++;
            }
            else return ans;
            current_time++;
        }

        return ans;
    }
};