class MyCircularDeque {
public:
    vector<int> circular_queue;
    int k,rear,front,count;
    MyCircularDeque(int k) {
        circular_queue.resize(k,-1);
        this->k=k;
        this->rear=k-1,this->front=0,this->count=0;
    }
    
    bool insertFront(int value) {
        if(count==k)
            return false;
        // circular queue ke concept ko use karo don't do for loop here
        front=(front-1+k)%k,count++;
        circular_queue[front]=value;
        return true;
    }
    
    bool insertLast(int value) {
        if(count==k)
            return false;
        rear=(rear+1)%k,count++;
        circular_queue[rear]=value;
        return true;
    }
    
    bool deleteFront() {
        if(count==0)
            return false;
        front=(front+1)%k,count--;
        return true;
    }
    
    bool deleteLast() {
        if(count==0)
            return false;
        rear=(rear-1+k)%k;
        count--;
        return true;
    }
    
    int getFront() {
        if(count==0)
            return -1;
        return circular_queue[front];
    }
    
    int getRear() {
        if(count==0)
            return -1;
        return circular_queue[rear];
    }
    
    bool isEmpty() {
        return count==0;
    }
    
    bool isFull() {
        return count==k;
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