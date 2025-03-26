class MyStack {
    public:
        queue<int> q;

    // Helper function to reverse the queue
    void rev(queue<int>& q) {
        if (q.empty()) {
            return;
        }
        int temp = q.front(); // Store the front element
        q.pop();              // Remove the front element
        rev(q);               // Recursively reverse the rest of the queue
        q.push(temp);         // Add the stored element back to the queue
    }

    // Constructor
    MyStack() {
    }
        
    // Push an element onto the stack
    void push(int x) {
        q.push(x);
    }
        
    // Pop the top element from the stack
    int pop() {
        rev(q);               // Reverse the queue to access the last element
        int ans = q.front();  // Get the front element (last element of original queue)
        q.pop();              // Remove the front element
        rev(q);               // Reverse the queue back to its original order
        return ans;
    }
        
    // Get the top element of the stack
    int top() {
        rev(q);               // Reverse the queue to access the last element
        int ans = q.front();  // Get the front element (last element of original queue)
        rev(q);               // Reverse the queue back to its original order
        return ans;
    }
        
    // Check if the stack is empty
    bool empty() {
        if (!q.empty()) {
            return 0;         // Return false if the queue is not empty
        }
        return 1;             // Return true if the queue is empty
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