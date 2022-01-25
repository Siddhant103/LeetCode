class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i=1;
        
        if(arr.size()<3)
            return false;
        
        while(i<arr.size() && arr[i]>arr[i-1]){
            i++;
        }
        cout<<i<<endl;
        if(i==arr.size() || i==1)
            return false;
        
       
        while(i<arr.size() && arr[i]<arr[i-1]){
            i++;
        }
        cout<<i<<endl;
        
        if(i==arr.size())
            return true;
        
        return false;
    }
};