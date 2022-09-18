class Solution {
public:
    int trap(vector<int>& height) {
// // -----------O(N) Time and Space------------         
//         int n=size(height);
//         vector<int> leftmax,rightmax(n,0);
//         int lm=0,rm=0;
        
//         for(int i=0;i<n;i++){
//             leftmax.push_back(lm);
//             lm=max(lm,height[i]);
//         }
        
//         for(int i=n-1;i>=0;i--)
//         {
//             rightmax[i]=rm;
//             rm=max(rm,height[i]);
//         }
        
        
//         int ans=0;
//         for(int i=0;i<n;i++){
//             if(height[i]<leftmax[i] and height[i]<rightmax[i])
//                 ans+=min(leftmax[i],rightmax[i])-height[i];
//         }
//         return ans;
        
        
        
        int leftmax=0,rightmax=0,left=0,right=height.size()-1,ans=0;
        while(left<right){
            if(height[left]<height[right]){
                
                if(height[left]>=leftmax)
                    leftmax=height[left];
                else
                    ans+=leftmax-height[left];
                
                left++;
            }
            else{
                if(height[right]>=rightmax)
                    rightmax=height[right];
                else
                    ans+=rightmax-height[right];
                
                right--;
                    
            }
        }
        return ans;
    }
};
