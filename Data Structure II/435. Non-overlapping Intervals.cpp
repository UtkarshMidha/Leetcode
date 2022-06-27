bool comp(vector<int> &a,vector<int> &b) {
	return a[1]<b[1];
}
class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int counter=0,p1=intervals[0][0],p2=intervals[0][1];
        if(intervals.size()==1) return 0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<p2 or intervals[i][1]<p2) counter++;
            else{
                p1=intervals[i][0];
                p2=intervals[i][1];
            }
        }
        return counter;
    }
};
