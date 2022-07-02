class Solution {

private:
    int maxDimension(int len,vector<int>& cuts){
        sort(cuts.begin(),cuts.end());
        
        int n=cuts.size();
        int ans=max(cuts[0],len-cuts[n-1]);
        
        for(int i=n-1;i>0;i--)
            ans=max(ans,cuts[i]-cuts[i-1]);
        
        return ans;
    }
    
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        return (int) ((long) maxDimension(h,horizontalCuts)* maxDimension(w,verticalCuts) % 1000000007);
    }
};
