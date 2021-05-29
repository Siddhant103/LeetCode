class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        uint32_t mask = 1;
        
        for(int i=0;i<32;i++){
            if((n & mask) != 0)
                count++;
            mask = mask << 1;
        }
        
        return count;
    }
};