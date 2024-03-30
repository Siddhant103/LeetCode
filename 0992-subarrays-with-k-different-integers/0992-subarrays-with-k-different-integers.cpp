int atMostKDistinct(vector<int>& A,int n,int k){
    int count = 0;
    int left = 0;
    int right = 0;
    
    unordered_map<int,int> mp;
    
    while(right < n){
        
        //add current element in the map
        if(mp.find(A[right]) == mp.end()){
            mp[A[right]] = 1;
        }else{
            mp[A[right]]++;
        }
        
        while(mp.size() > k){
            mp[A[left]]--;
            if(mp[A[left]] == 0){
                mp.erase(A[left]);
            }
            left++;
        }
        
        count += right-left+1;
        right++;
    }
    
    
    return count;
}


class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int k) {
        int n = A.size();
        return atMostKDistinct(A,n,k) - atMostKDistinct(A,n,k-1);
    }
};