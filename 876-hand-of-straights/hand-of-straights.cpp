class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;
        map<int,int>mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        int grp=hand.size()/groupSize;
        while(grp){
            auto it=mp.begin();
            int val=it->first;
            mp[val]--;
            if(mp[val]==0)mp.erase(val);
            int cnt=1;
            while(cnt<groupSize && mp.find(val+cnt)!=mp.end()){
                mp[val+cnt]--;
                if(mp[val+cnt]==0)mp.erase(val+cnt);
                cnt++;
            }
            if(cnt!=groupSize)return false;
            grp--;
        }
        return true;        
    }
};