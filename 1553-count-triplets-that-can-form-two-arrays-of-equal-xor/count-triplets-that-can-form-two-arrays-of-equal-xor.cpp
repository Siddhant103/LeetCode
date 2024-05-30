class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        int pre[n];
        pre[0]=arr[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]^arr[i];
        }
        int ct=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=pre[j-1]^((i==0)?0:pre[i-1]);
                for(int k=j;k<n;k++){
                    int b=pre[k]^pre[j-1];
                    if(a==b){
                        ct++;
                    }
                }
            }
        }
        return ct;
    }
};