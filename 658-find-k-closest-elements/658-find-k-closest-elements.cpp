class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;
        
        for(int i: arr){
            pq.push(make_pair(abs(i - x), i));
            cout << pq.top().second << endl;
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        sort(result.begin(), result.end()); 
        
        return result;
    }
};