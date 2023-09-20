class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        if(nums.size() == 1)return (nums[0]==x)?1:-1;
        int ans=INT_MAX;
        unordered_map<int,int> mp;
        for(int i=0,sum=0;i<nums.size() and sum<=x;i++){
            mp[sum]=i;
            sum+=nums[i];
            
        }
        
        for(int right=nums.size()-1,sum=0;right>=0 and sum<=x;right--){
            auto it=mp.find(x-sum);
            if(it !=end(mp) and  it->second<=right+1 )
                ans=min(ans,(int)nums.size()-1-right+it->second);
                
            sum+=nums[right];
        }
        return ans==INT_MAX?-1:ans;
    }
};
