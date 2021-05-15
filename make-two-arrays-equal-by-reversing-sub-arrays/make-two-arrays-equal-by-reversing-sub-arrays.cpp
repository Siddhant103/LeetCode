class Solution {
public:
    bool canBeEqual(vector<int>& array_a, vector<int>& array_b) {
        
  if(array_a.size() != array_b.size())
    return false;
  sort(array_a.begin(), array_a.end());
  sort(array_b.begin(), array_b.end());
  
  for(int i=0;i<array_a.size();i++){
    if(array_a[i]!=array_b[i])
      return false;
  }
  
  return true;
    }
};