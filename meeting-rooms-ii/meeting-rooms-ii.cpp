class Solution {
public:
    
    static bool comp(const vector<int>& a, const vector<int>& b){
        return a[0]<b[0]; 
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        
        for(vector<int> v: intervals){
            cout<< v[0] << " " <<v[1]<<endl;
        }
        
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);
        
        for(int i=1;i<intervals.size();i++){
            if(pq.top() <= intervals[i][0])    
                pq.pop();
            pq.push(intervals[i][1]);
            
        }
        
        return pq.size();
    }
};