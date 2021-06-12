class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        //pq
        priority_queue<pair<int, int>> pq;
        
        for(auto range: ranges){
            pq.push({range[0], range[1]});
        }
        
        /*while(!pq.empty()){
            cout << pq.top().first << " " << pq.top().second << endl;
            pq.pop();
        }*/
        
        for(int i = right; i >= left; i--){
            cout << i << " ";
            while(pq.size() > 0 && !(i >= pq.top().first && i <= pq.top().second)){
                pq.pop();
            }
            
            if(pq.size() == 0){
                return false;
            }
        }
        
        return true;
    }
};