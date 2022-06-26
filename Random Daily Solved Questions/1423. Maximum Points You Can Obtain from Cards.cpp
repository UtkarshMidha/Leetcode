class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=size(cardPoints);
        vector<int> sumFront(n+1,0),sumBack(n+1,0);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=cardPoints[i];
            sumFront[i+1]=sum;
        }
        sum=0;
        for(int i=n-1;i>=0;--i)
        {
            sum+=cardPoints[i];
            sumBack[i]=sum;
        }
        int maxsum=0;
        for(int i=k;i>=0;i--)
            maxsum=max(maxsum,sumFront[i]+sumBack[n-(k-i)]);
        return maxsum;
    }
};
