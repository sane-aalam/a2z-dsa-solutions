class MyCircularDeque {
public:
    // to keep track the maximum size DQ
    int maxSize;
    // STL - dobuly linked list creation using STL
    deque<int>dequeContainer;
     MyCircularDeque(int k) {
        maxSize = k;
    }
    
    bool insertFront(int value) {
        // dequeContainer is full, not possible to insert new element into front
         if(dequeContainer.size() == maxSize){
            return false;
         }
         dequeContainer.push_front(value);
         return true;
    }
    
    bool insertLast(int value) {
        // dequeContainer is full, not possible to insert new element into front
         if(dequeContainer.size() == maxSize){
            return false;
         }
         dequeContainer.push_back(value);
         return true;
    }
    
    bool deleteFront() {
         // dequeContainer is alredy empty,then not possbile to remove into front
         if(dequeContainer.size() == 0){
            return false;
         }
         dequeContainer.pop_front();
         return true;
    }
    
    bool deleteLast() {
        // dequeContainer is alredy empty,then not possbile to remove into front
         if(dequeContainer.size() == 0){
            return false;
         }
         dequeContainer.pop_back();
         return true;
    }
    
    int getFront() {
         if(dequeContainer.size() == 0){
            return -1;
         }
         int frontElement = dequeContainer.front();
         return frontElement;
    }
    
    int getRear() {
         if(dequeContainer.size() == 0){
            return -1;
         }
         int backElement = dequeContainer.back();
         return backElement;
    }
    
    bool isEmpty() {
        // if Dq size is zero, empty hai
        return (dequeContainer.size() == 0);
    }
    
    bool isFull() {
        // if dq size is maximumSize equal, full hai
        return (dequeContainer.size() == maxSize);
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