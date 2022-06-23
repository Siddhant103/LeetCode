class Solution {
public:
    static bool comp(const vector<int>& a,const vector<int>& b){
        if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comp);
        
        for(vector<int> i: courses){
            cout<<i[0]<<" "<<i[1]<<endl;
        }
        
        priority_queue<int> pq;
        int time = 0;
        
        for(vector<int> course: courses){
            if(course[0]<=course[1]){
                if(course[0]+time<=course[1]){
                    time += course[0];
                    pq.push(course[0]);
                } else{
                    if(pq.top() > course[0]){
                        time -= pq.top();
                        time += course[0];
                        pq.pop();
                        pq.push(course[0]);
                    }
                }
            }
        }
        
        return pq.size();
    }
};