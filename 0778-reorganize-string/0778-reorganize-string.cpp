class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> count;
        int maxCount = 0;
        for (char c: s) {
            count[c]++;
            maxCount = max(maxCount, count[c]);
        }

        // if (maxCount > n / 2) {
        //     return "";
        // }

        priority_queue<pair<int, int>> pq;

        for (auto it: count) {
            pq.push({it.second, it.first});
        }

        string result = "";
        while (pq.size() >= 2) {
            auto [freq1, element1] = pq.top(); pq.pop();
            auto [freq2, element2] = pq.top(); pq.pop();
            result += element1;
            result += element2;
            if (--freq1 > 0) {
                pq.push({freq1, element1});
            }
            if (--freq2 > 0) {
                pq.push({freq2, element2});
            }
        }

        if (!pq.empty()) {
            auto [freq, element] = pq.top();
            if (freq > 1) {
                cout << "end\n";
                return "";
            }
            result += element;
        }
        cout << "start\n";
        return result;
    }
};