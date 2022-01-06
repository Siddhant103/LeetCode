class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> map;
        for (int i = 0;i < trips.size();++i) {
            map[trips[i][1]] += trips[i][0]; //filled seats increase when we pick up passengers
            map[trips[i][2]] -= trips[i][0]; //filled seats decrease when we drop off the passengers
        }
        for (auto it = map.begin(); it != map.end();it++) { //map is sorted on keys( key is time instant)
            capacity -= it->second;
            if (capacity < 0) { //if at any time instant, vacant seats < no of passengers to pick up, return false
                return false;
            }
        }
        return true;
    }
};