class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        
        priority_queue<int> pq;
        
        for(int i: stones){
            pq.push(i);
        }
        
        while(pq.size()>1){
            int s1 = pq.top(); pq.pop();
            int s2 = pq.top(); pq.pop();
            cout<<s1<<" "<<s2<<endl;
            if(s1!=s2)
                pq.push(abs(s1-s2));
        }
        
        if(pq.size()==0) return 0;
        
        return pq.top();
    }
};