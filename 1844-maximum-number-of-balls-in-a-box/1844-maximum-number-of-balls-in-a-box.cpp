class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int,int>map;
        int n, i, sum;

        for (int i=lowLimit;i<highLimit+1;i++){
            sum = 0,n = i;
            while (n > 0){    
                sum += n % 10;    
                n /= 10;    
            }
            map[sum]++;           
        }

        int maxx = 0;
        for (auto v: map)
            if (v.second > maxx)   
                maxx = v.second;          
                
        return maxx;
    }      
};