class MyQueue {
    stack<int> help;
    stack<int> help1;
    
public:
    MyQueue() {
        
        
        
    }
    
    void push(int x) {
        
        help.push(x);
        
    }
    
    int pop() {
        
          while(help.size())
            {  help1.push(help.top());help.pop();}
            
          int temp = help1.top();   
          help1.pop();
            
          while(help1.size()){
                
                help.push(help1.top());help1.pop();
            }
            
            
       return temp; 
        
        
    }
    
    int peek() {
        
        
                while(help.size())
            {  help1.push(help.top());help.pop();}
            
        int temp = help1.top();   
 
            
            while(help1.size()){
                
                help.push(help1.top());help1.pop();
            }
            
            
       return temp; 
        
    }
    
    bool empty() {
        
        
        return help.empty();
        
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
