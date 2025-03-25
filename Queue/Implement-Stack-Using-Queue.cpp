class MyStack {
    public:
        queue<int> q;
    void rev(queue<int>&q){
        if(q.empty()){
            return;
        }
        int temp = q.front();
        q.pop();
        rev(q);
        q.push(temp);
    }
        MyStack() {
            
        }
        
        void push(int x) {
            q.push(x);
        }
        
        int pop() {
            rev(q);
            int ans=q.front();
            q.pop();
            rev(q);
            return ans;
        }
        
        int top() {
            rev(q);
            int ans=q.front();
           // q.pop();
            rev(q);
            return ans;
        }
        
        bool empty() {
            if(!q.empty()){
                return 0;
            }
            return 1;
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