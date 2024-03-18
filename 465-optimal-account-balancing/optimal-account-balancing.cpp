class Solution {
public:
    int findMinTransactions(vector<int> &balances, int index) {
        if (balances.size() == 0 || index >= balances.size()) {
            return 0;
        }
        
        if (balances[index] == 0) {
            return findMinTransactions(balances, index + 1);
        }
        
        int minTransactions = INT_MAX - 1;
        int currBalance = balances[index];
        
        for (int i=index + 1;i<balances.size();i++) {
            int nextBalance = balances[i];
            if (currBalance * nextBalance < 0) {
                balances[i] = currBalance + nextBalance;
                minTransactions = min(minTransactions, 1 + findMinTransactions(balances, index + 1));
                balances[i] = nextBalance;
                // if (currBalance + nextBalance == 0) {
                //     break;
                // }
            }
        }
        
        return minTransactions;
    }
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> m;
        for (auto transaction: transactions) {
            int from = transaction[0];
            int to = transaction[1];
            int amount = transaction[2];
            m[from] -= amount;
            m[to] += amount;
        }
        
        vector<int> balances;
        
        for (auto [member, balance]: m) {
            cout << member << " " << balance << endl;
            if (balance != 0) {
                balances.push_back(balance);
            }
        }
        
        return findMinTransactions(balances, 0);
    }
};