class MyCircularDeque {
public:
    vector<int> v;
    int front, rear, size;
        
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        v.resize(k, -1);
        front = -1;
        rear = -1;
        size = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull())
            return false;
        if(isEmpty()){
            front = 0;
            rear = 0;
            v[front] = value;
            return true;
        }
        if(front == 0){
            front = size - 1;
        } else{
            front = (front - 1) % size;
        }
        v[front] = value;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull())
            return false;
        if(isEmpty()){
            front = 0;
        }
        rear = (rear + 1) % size;
        v[rear] = value;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty())
            return false;
        
        v[front] = -1;
        if(front == rear){
            front = -1;
            rear = -1;
        } else{
            front = (front + 1) % size;
        }
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty())
            return false;
        
        v[rear] = -1;
        if(front == rear){
            front = -1;
            rear = -1;
            return true;
        }
        if(rear == 0){
            rear = size - 1;
        } else{
            rear = (rear - 1) % size;
        }
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty())
            return -1;
        
        return v[front];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty())
            return -1;
        
        return v[rear];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if(front == -1 && rear == -1){
            return true;
        }
        
        return false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return ((rear + 1) % size == front);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */