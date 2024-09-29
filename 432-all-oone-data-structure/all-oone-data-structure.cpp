class AllOne {
    /** Initialize your data structure here. */
    list<pair<int,unordered_set<string>>> ls;                                   // double linked list for pair of (value, unordered_set of keys), sorted
    unordered_map<string,list<pair<int,unordered_set<string>>>::iterator> mp;   // hash map for mapping key to list iterator
public:
    AllOne() {   
    }
    
    void inc(string key) {
        if (!mp.count(key))
            mp[key] = ls.insert(ls.begin(),{0,{key}});                          // if key doesn't exist, insert one with value=0 into list, and update map
        
        auto itr = mp[key];                 // get the iterator of list for the key
        auto itrNext = next(itr);           // get the next iterator of itr
        if (itrNext==ls.end() || itr->first+1 < itrNext->first)                 // two cases: need to create a new element for the list
            itrNext = ls.insert(itrNext,{itr->first+1,{}});
        itrNext->second.insert(key);        // insert key into the element with value == itr->first+1
        mp[key] = itrNext;                  // update mp[key]
        
        itr->second.erase(key);             // remove key from the element, pointed by itr
        if (itr->second.empty())            // if itr->hashSet with keys is empty, remove this element from list
            ls.erase(itr);
    }

    void dec(string key) {
        if (!mp.count(key))                 // if key doesn't exist, return
            return;
        auto itr = mp[key];                 // get the iterator of the list for the key
        auto itrPrev = prev(itr);           // get the previous iterator of itr
        mp.erase(key);                      // remove key from hash map first
        if (itr->first>1) {                 // for the case, itr->value - 1 > 0
            if (itr==ls.begin() || itr->first-1 > itrPrev->first)               // two cases: need to create a new element for the list
                itrPrev = ls.insert(itr,{itr->first-1,{}});
            itrPrev->second.insert(key);    // insert key into the element with value == itr->first-1
            mp[key] = itrPrev;              // create mp[key]
        }
        itr->second.erase(key);             // remove key from the element, pointed by itr
        if (itr->second.empty())            // if itr->hashSet with keys is empty, remove this element from list
            ls.erase(itr);
    }
    
    string getMaxKey() {
        return mp.empty() ? "" : *ls.rbegin()->second.begin();                  // return the last element of the list
    }
    
    string getMinKey() {
        return mp.empty() ? "" : *ls.begin()->second.begin();                   // return the first element of the list
    }
};