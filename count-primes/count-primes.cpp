class Solution {
public:
    int countPrimes(int n) {
        // 2 3 4 5 6 7 8 9 10 11 12
        
        vector<int> primes(n,true);
        
        for(int i=2;i*i<n;i++){
            if(primes[i]){
                for(int j=2;j*i<n;j++){
                    primes[i*j]=false;
                }
            }
        }
        
        int count=0;
        for(int i=2;i<n;i++){
            if(primes[i])
                count++;
        }
        
        return count;
        
        /*if(n<2)
            return 0;
        
        int count = 0;
        int i,j;
        for(i=2;i<n;i++){
            for(j=2;j<i;j++){
                if(i%j==0)
                    break;
            }
            
            if(j==i)
                count++;
        }
        
        return count;*/
        
    }
};