class MyQueue {
private:
    stack<int> st;

public:
    MyQueue() {
        // Constructor 
    }
    
    // Simple Rotation Logic using a temporary array loop
    void push(int x) {
        vector<int> temp;
        
        //1. make vector
        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        
        // 2. push new element in stack so this will pop first for FIFO logic
        st.push(x);
        
        // 3.Reinsert all previous elements in the stack
        for (int i = temp.size() - 1; i >= 0; i--) {
            st.push(temp[i]);
        }
    }
    
    
    int pop() {
        int front = st.top();
        st.pop();
        return front;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
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
