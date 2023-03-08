class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=1;
        int low=1,high=*max_element(piles.begin(),piles.end());
        while(low<high){
            int mid=low+(high-low)/2;
            int temp=0;
            for(int i=0;i<piles.size();++i){
                temp+=piles[i]/mid;
                if(piles[i]%mid)
                    temp++;
            }
            if(temp>h)
                low=mid+1;
            else
                high=mid;
        }
        return low;
    }
};
