class MyQueue {
public:
        deque<int>d;
    MyQueue() {
        
    }
    
    void push(int x) {
        d.push_back(x);
    }
    
    int pop() {
        int ele = d.front();
        d.pop_front();
        return ele;
    }
    
    int peek() {
        return d.front();
    }
    
    bool empty() {
        return(d.empty());
    }
};