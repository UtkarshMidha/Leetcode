class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     vector<int> res;
        int temp=0;
        int prod=1;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0)
                temp++;
            else
                prod*=nums[i];
        }
        if(temp>1){
            for(int i=0;i<nums.size();++i)
                res.push_back(0);
        }
        else{
            
                for(int i=0;i<nums.size();++i){
                    if(nums[i]==0){
                        res.push_back(prod);}
                        else if(temp==1)
                            res.push_back(0);
                        else{
                            res.push_back(prod/nums[i]);
                        }
                    }
        }
    return res;
    }
};
