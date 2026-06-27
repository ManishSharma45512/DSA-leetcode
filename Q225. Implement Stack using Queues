class MyStack {
private:
    queue<int> q; // Queue creation

public:
    MyStack() {
        // Constructor will empty
    }
    
    // Time Complexity: O(N) due to rotation
    void push(int x) {
        int current_size = q.size();
        
        // 1. push element normal queue at back
        q.push(x);
        
        // 2.Rotate the queue
        for (int i = 0; i < current_size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    // Time Complexity: O(1)
    int pop() {
        int top_element = q.front();
        q.pop();
        return top_element;
    }
    
    // Time Complexity: O(1)
    int top() {
        return q.front();
    }
    
    // Time Complexity: O(1)
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
