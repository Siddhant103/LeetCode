class Solution {
public:
    int brokenCalc(int X, int Y) {
        /*
        2 operations :
            multiply by 2
            minus 1
            
        convert X->Y in minimum steps;
        */
        int steps=0;
        while(Y>X){
            Y = (Y%2>0)?Y+1:Y/2;
            steps++;
        }   
        
        return steps+X-Y;
    }
};