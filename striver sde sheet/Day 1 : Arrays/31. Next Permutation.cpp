class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //next_permutation(begin(nums), end(nums));
        int n=size(nums),pos;
        if(n<2) return; 
        int i;
        for(i=n-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
              break;
            }
        }
        if(i<0)
            reverse(nums.begin(),nums.end());
            
        else{
            for(pos=n-1;pos>i;pos--){
                if(nums[pos]>nums[i])
                    break;
            }
            swap(nums[pos],nums[i]);
            reverse(nums.begin()+i+1,nums.end());
        }
    }
};
