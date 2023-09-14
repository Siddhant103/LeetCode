class Solution {
public:
    vector<string> findItinerary(vector<vector<string>> tickets) {
        unordered_map<string, multiset<string>> m;
        for (const vector<string> & ticket : tickets) {
            m[ticket[0]].insert(ticket[1]);
        }
        
        vector<string> march = { "JFK" };
        vector<string> results;
        while (march.empty() == false) {
            string & from = march.back();
            if ((m.find(from) != m.end()) && (m[from].empty() == false)) {
                multiset<string> & to = m[from];
                march.push_back(*(to.begin()));
                to.erase(to.begin());
            } else {
                results.push_back(march.back());
                march.pop_back();
            }
        }
        
        reverse(results.begin(), results.end());
        return results;
    }
};