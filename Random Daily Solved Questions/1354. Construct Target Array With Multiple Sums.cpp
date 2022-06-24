class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        int n  = target.size();
        unsigned int sum = 0;
        
        priority_queue<int, vector<int>> pq;
        
        for(int i=0; i<n; i++) {
            
             pq.push(target[i]);
             sum += target[i];
        }
           
        
        while(pq.top() != 1) {
            
            int cur = pq.top();
            pq.pop();
            
            if(sum - cur == 1)
                return true;
            
            if(sum - cur == 0)
                return false;
            
            int x = cur % (sum - cur);
            sum = sum - cur + x;
            
            if(x == 0 || x == cur)
                return false;
            
            pq.push(x);
            
        }
        
        return true;
    }
};
