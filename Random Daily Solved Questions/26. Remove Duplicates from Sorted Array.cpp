class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     int n=nums.size();
        if(n==0)
             return 0;
       int low=0;
        int i=1;
         while(i<n)
         {
             if(nums[i]!=nums[i-1])
                nums[++low]=nums[i];
              i++;
         }
         return low+1;
    }
};
