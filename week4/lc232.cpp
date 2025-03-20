class MyQueue {
public:
    vector<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push_back(x);
    }
    
    int pop() {
        int a = peek();
        s2.pop_back();
        return a;
    }
    
    int peek() {
        if(s2.size() == 0){
            while(s1.size() > 0){
                int a = s1.back();
                s1.pop_back();
                s2.push_back(a);
            }
        }
        return s2.back();
    }
    
    bool empty() {
        return s1.size() == 0 && s2.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */