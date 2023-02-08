class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;
        if(nums[0]==0) return -1;
        int maxreach=nums[0] , step=nums[0], jump=1;
        for(int i=1;i<n;i++){
            if(i==n-1)
            return jump;
            
            maxreach=max(maxreach,i+nums[i]);
            step--;
            if(step==0){
                jump++;
            
                if(i>maxreach)
                return -1;
            
                step=maxreach-i;
            }
            
        }
        return -1;
    }
};
