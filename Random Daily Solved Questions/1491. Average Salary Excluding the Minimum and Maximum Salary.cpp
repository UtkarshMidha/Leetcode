class Solution {
public:
    double average(vector<int>& salary) {
        int maxx=salary[0],minn=salary[0];
        double ans=0.0;
        int n=0;
        for (int x:salary){
            if(maxx<x)
                maxx=x;
            if(minn>x)
                minn=x;
            ans+=x;
            ++n;
        }
        return (ans-minn-maxx)/(n-2);
    }
};
