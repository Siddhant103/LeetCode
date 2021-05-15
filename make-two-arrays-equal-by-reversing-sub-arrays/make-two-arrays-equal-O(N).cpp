class Solution {
public:
    bool canBeEqual(vector<int>& array_a, vector<int>& array_b) {
        
      if(array_a.size() != array_b.size())
        return false;

      unordered_map<int,int> m;

      for(int i=0;i<array_a.size();i++){
        m[array_a[i]]++;
        m[array_b[i]]--;
      }

      for(auto itr=m.begin(); itr!=m.end(); ++itr){
        if(itr->second!=0){
          return false;
        }
      }

      return true;
    }
};
