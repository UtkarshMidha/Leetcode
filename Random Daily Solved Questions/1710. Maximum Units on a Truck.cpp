class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        auto comp = [](auto a, auto b){
            return (a[1] > b[1]);   
        };
        sort(boxTypes.begin(),boxTypes.end(),comp);   
        int sum=0;
        for( auto c:boxTypes)
        {
            // cout<<"["<<c[0]<<","<<c[1]<<"] "<<endl;
            if(c[0]>=truckSize)
                return sum+truckSize*c[1];
            truckSize-=c[0];
            sum+=c[0]*c[1];
        }
        return sum;
    }
};
