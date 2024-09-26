class MyCalendar {
    map<int, int> books;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        auto itr = books.lower_bound(start);
        if(itr != books.end() && itr->first < end) 
            return false;
        
        if(itr != books.begin () && start < (--itr)->second)
            return false;
        //In all other cases update abd return true
        books[start] = end;
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */