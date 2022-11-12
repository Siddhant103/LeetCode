class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_heap.size() == 0 || max_heap.top() >= num){
            max_heap.push(num);
        } else{
            min_heap.push(num);
        }
        cout << "Pushing done for " << num << endl;
        if(max_heap.size() > (min_heap.size()+1))
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if(max_heap.size()+1<min_heap.size())
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        cout << "Balance done" << endl;
    }
    
    double findMedian() {
        cout << "In findMedian" << endl;
        if(max_heap.size() > min_heap.size()){
            return max_heap.top();
        } else if(max_heap.size() < min_heap.size()){
            return min_heap.top();
        } else{
            return (max_heap.top() + min_heap.top())/2.0;
        }
            
    }
    
    void balance(){
        
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */