class CustomStack {
public:
    vector<int> stack;
    int top=-1,size;
    CustomStack(int maxSize) {
        stack.resize(maxSize,-1);
        size=maxSize;
    }
    
    void push(int x) {
        if(top<size-1){
            top++;
            stack[top]=x;
        }
    }
    
    int pop() {
        if(top<0)
            return -1;
        return stack[top--];
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,top+1);i++){
            stack[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */