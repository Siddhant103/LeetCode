class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> setJewel;
        int count = 0;
        
        for(char j: jewels){
            setJewel.insert(j);
        }
        
        for(char s: stones){
            if(setJewel.find(s) != setJewel.end()){
                count++;
            }
        }
        
        return count;
    }
};