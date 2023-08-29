class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        if (mainTank <= 4)
         return mainTank * 10;

        int count = 0;
        while (mainTank >= 5) {    
            mainTank = mainTank - 5;
            count++;  
            if (additionalTank >= 1 ) {
                mainTank += 1;
                additionalTank--;
            }
        }
        return count * 50 + mainTank * 10;
    }
};