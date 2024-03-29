class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i=0;
        for(auto c:pushed){
            s.push(c);
            while(!s.empty() and s.top()==popped[i] ){
                s.pop();
                ++i;
                    
            }
        }
        return s.empty();
    }
};
