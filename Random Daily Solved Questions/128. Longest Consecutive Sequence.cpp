class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // ---------O(nlogn)-----------
        // sort(nums.begin(),nums.end());
        // if(nums.size()<2) return nums.size();
        // int prev=nums[0],counter=0,maxx=0;
        // for(int i=1;i<nums.size();i++)
        // {
        //     if(prev+1==nums[i])
        //     {
        //         counter++;
        //         maxx=max(maxx,counter);
        //             prev=nums[i];
        //     }
        //     else  if(prev==nums[i])
        //         continue;
        //     else {
        //         counter=0;
        //         prev=nums[i];
        //     }
        // }
        // return max(maxx,counter)+1;
        
        //---------O(N)----------
        if(nums.size()<2) return nums.size();
        unordered_set<int> record(nums.begin(),nums.end());
        int res = 1;
        for(int n : nums){
            if(record.find(n)==record.end()) continue;
            record.erase(n);
            int prev = n-1,next = n+1;
            while(record.find(prev)!=record.end()) record.erase(prev--);
            while(record.find(next)!=record.end()) record.erase(next++);
            res = max(res,next-prev-1);
        }
        return res;
    }
};
