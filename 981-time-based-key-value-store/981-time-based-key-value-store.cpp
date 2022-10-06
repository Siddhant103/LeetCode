class TimeMap {
public:
   /** Initialize your data structure here. */
   unordered_map<string, map<int, string>> m;

   TimeMap() {}

   void set(string key, string value, int timestamp) {
      auto& inner_map = m[key];
      inner_map[-timestamp] = value;
   }

   string get(string key, int timestamp) {
      auto i = m.find(key);
      if (i == m.end()) 
          return "";
       
      auto j = i->second.lower_bound(-timestamp);
      return j != i->second.end() ? j->second : "";
   }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */