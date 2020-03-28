class MyCircularQueue {
public:
    vector<int> v;
    int front, end, cap;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k): v(k), front(-1), end(-1), cap(k) {
        
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        
        end = next(end);
        v[end] = value;
        if (front == -1) front = end;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        
        if (front == end) {
            front = end = -1; // only 1 element
        } else {
            front = next(front);
        }
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return front != -1 ? v[front] : -1;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return end != -1 ? v[end] : -1;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return front == -1;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return !isEmpty() && next(end) == front;
    }
private:
    int next(int pos) {
        return (pos + 1) % cap;
    }
    
    int prev(int pos) {
        return (pos - 1 + cap) % cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */