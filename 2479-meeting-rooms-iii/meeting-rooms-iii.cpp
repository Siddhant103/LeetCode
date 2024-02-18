class cmp {
public:
    bool operator()(pair<long long,int> &a,pair<long long,int> &b) {
        return (a.first==b.first?a.second>b.second:a.first>b.first);
    }
};
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meet) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>> ,cmp> p;
        int freq[101]={};
        sort(begin(meet),end(meet));
        for(int i=0;i<n;i++)p.push({0,i});
        for(auto &x: meet)
        {
            while(p.top().first<x[0])
            {
                p.push({x[0],p.top().second});
                p.pop();
            }
            pair<long long,int> temp=p.top();
            p.pop();
            freq[temp.second]++;
            temp.first+=(x[1]-x[0]);
            p.push(temp);
        }
        int ans=0;
        for(int i=0;i<101;i++)if(freq[ans]<freq[i])ans=i;
        return ans;
    }
};