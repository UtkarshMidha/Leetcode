class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // int start=-1,end=-1;
        // bool flag=true;
        // for (int i=0;i<nums.size();i++){
        //     if(flag and nums[i]==target)
        //     {
        //         flag=false;
        //         start=i;
        //     }
        //     if(nums[i]==target)
        //         end=i;
        // }
        // if(start==-1)
        //     return {-1,-1};
        // return{start,end};
        
        
        
        vector<int> ans;
        int i=0;
        int j=nums.size()-1;
            while(i<=j){
                //int mid=(i+j)/2;
                int mid=i+(j-i)/2;
                if(nums[mid]==target){
                    while(nums[i]!=target) i++;
                    ans.push_back(i);
                    while(nums[j]!=target)j--;
                    ans.push_back(j);
                    break;
                }
                if(nums[mid]<target){
                    i=mid+1;
                }
                else if(nums[mid]>target){
                    j=mid-1;
                }
                
            }
        if(ans.size()==0) return {-1,-1};
        return ans;
        
        
    }
};
