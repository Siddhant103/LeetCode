class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int left = 0;
        int n = arr.size();
        
        while(left + 1 < n && arr[left] <= arr[left + 1])
            left++;
        
        if(left == n - 1)
            return 0;
        
        int right = n - 1;
        while(right >= left && arr[right - 1] <= arr[right])
            right--;
        
        int ans = min(n-left-1, right);
        
        int i = 0, j = right;
        
        while(i<=left and j<n)
        {
            if( arr[i] <= arr[j] )
            {
                ans=min(ans, j-i-1);
                i++;
            }
            else 
                j++;
        }
        
        return ans;
    }
};