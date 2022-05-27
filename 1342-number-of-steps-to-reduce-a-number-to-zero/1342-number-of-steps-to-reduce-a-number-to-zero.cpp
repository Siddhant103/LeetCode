class Solution {
public:
    int numberOfSteps (int n) {
        int steps=0;
        while(n){
            if(n%2==0)
                n/=2;
            else{
                n--;
            }
            steps++;
        }
        return steps;
    }
};