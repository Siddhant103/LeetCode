class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> losers;
        set<int> players;
        
        for(vector<int> match: matches) {
            losers[match[1]]++;
            
            players.insert(match[0]);
            players.insert(match[1]);
        }
        
        vector<vector<int>> answer(2);
        for(int player: players) {
            if (!losers.count(player)) {
                answer[0].push_back(player);
            } else if (losers.count(player) && losers[player] == 1) {
                answer[1].push_back(player);
            }
        }
        
        return answer;
    }
};