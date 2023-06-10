class Solution {
private:
    bool check(int n, int mid, int mxS, int index){
        long sum = 0;
        int lb = max(0, mid - index);
        sum = (long)(mid - lb + 1) * 1LL * (lb + mid)/2;
        int rb = max(mid - (n - 1 - index), 0);
        sum += (long)(mid - rb + 1) *1LL * (rb + mid)/2;
        return (sum - mid) <= (long) mxS;
    }
public:
    int maxValue(int n, int index, int mS) {
        mS -=n;
        int lo = 0, hi = mS, ans = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(check(n, mid, mS, index)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans + 1;
    }
};