class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int res=INT_MAX, m=INT_MAX;
        priority_queue<int> pq;
        for(auto c:nums){
            c=c%2?c*=2:c;
            pq.push(c);
            m=min(m,c);
        }
        
        while(pq.top()%2==0){
            res=min(res,pq.top()-m);
            m=min(m,pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
                       
        }
        return min(res,pq.top()-m);
        
    }
};



