class Solution {
//-----------------BRUTE FORCE ---------------
// private:
//     int calculate(vector<int>& nums,int index,bool isUp ){
//         int maxx=0;
//         for(int i=index+1;i<nums.size();i++){
//             if((isUp and nums[i]>nums[index]) or (!isUp and nums[i]<nums[index]))
//                 maxx=max(1+calculate(nums,i,!isUp),maxx);
//         }
//         return maxx;
//     }
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         if(size(nums)<2) return size(nums);
//         return 1+max(calculate(nums,0,true),calculate(nums,0,false));
//     }
    
    //-----------------2 DP vectors used  and 2 loops
    // public:
    // int wiggleMaxLength(vector<int>& nums){
    //     int n=size(nums); 
    //     if(n<2) return n;
    //     vector<int> dp_up(n,1),dp_down(n,1);
    //     for(int i=1;i<n;i++){
    //         for(int j=0;j<i;j++){
    //             if(nums[i]>nums[j])
    //                 dp_up[i]=max(dp_up[i],1+dp_down[j]);
    //             else if(nums[i]<nums[j])
    //                 dp_down[i]=max(dp_down[i],1+dp_up[j]);
    //         }
    //     }
    // return max(dp_up[n-1],dp_down[n-1]);
    // }
    
    
    // COUNT THE NUMBER OF PEAKS AND VALLEY POINTS
    public:
     int wiggleMaxLength(vector<int>& nums){
         int peak=1,valley=1;
         int n=size(nums);
         
         if(n<2) return n;
         
         for(int i=1;i<n;i++){
             if(nums[i]>nums[i-1])
                 peak=valley+1;
             else if(nums[i]<nums[i-1])
                 valley=peak+1;
         }
         return max(valley,peak);
     }
};
