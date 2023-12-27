class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
       // //================1ST APPROACH=======================
       // int left=0,right=0,ans=0,n=neededTime.size();
       //  while(left<n and right<n){
       //      int remove_sum=0;
       //      int maxx=0;
       //      while(right<n and colors[left]==colors[right]){
       //          remove_sum+=neededTime[right];
       //          maxx=max(maxx,neededTime[right]);
       //          right++;
       //      }
       //      remove_sum-=maxx;
       //      ans+=remove_sum;
       //      left=right;
       //  }
       //  return ans;
        
        
        // //==============2ND APPROACH=========================
        int n=neededTime.size();
        int ans=0,curr_max=0;
        for(int i=0;i<n;i++){
            if(i>0 and colors[i]!=colors[i-1])
                curr_max=0;
            
            ans+=min(curr_max,neededTime[i]);
            curr_max=max(curr_max,neededTime[i]);
        }
        return ans;
        }
};
