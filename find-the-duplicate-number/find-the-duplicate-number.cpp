class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int i=0;
            
        while(i<arr.size()){
            if(arr[i]!=arr[arr[i]-1]){
                swap(arr[i], arr[arr[i]-1]);
            } else{
                i++;
            }
        }
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=i+1)
                return arr[i];
        }
        
        return -1;
    }
};