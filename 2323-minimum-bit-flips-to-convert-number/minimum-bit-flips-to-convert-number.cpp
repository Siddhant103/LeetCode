class Solution {
public:
    //we just check whether binary bit is equal or not 
    //if it is we do nothing otherwise we flips the bit and increase the count
    int minBitFlips(int start, int goal) 
    {   
        int flips=0;
		
		//iterate until both numbers get 0
        while(start || goal)
        {
			//check whether bits are equal or not, if not we flip the bit
            if(start%2 != goal%2)
                flips++;
            
            start /= 2;
            goal /= 2;
        }
        return flips;
        
    }
};