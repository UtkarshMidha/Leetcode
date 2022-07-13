class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1,num=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==num)count++;
            else count--;
            if(count==0){
                num=nums[i];
                count=1;
            }
        }
        return num;
    }
};
