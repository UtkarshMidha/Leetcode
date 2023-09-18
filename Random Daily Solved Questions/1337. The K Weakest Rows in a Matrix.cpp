class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> zeros(mat.size(),make_pair(-1, -1));
        //cout<<mat.size();
        //return zeros;
        int k1=0;
        for(auto c:mat){
            int counter=0;
            for(int i=0;i<c.size();i++){
                if(c[i]==1)
                    counter++;
            }
            zeros[k1].first=counter;
            zeros[k1].second=k1;
        k1++;
        }
        sort(zeros.begin(),zeros.end());
        // for(int i=0;i<zeros.size();i++)
        //     cout<<zeros[i].first<<" ";
        vector<int> ans;
        for(int i=0;i<k;i++)
            ans.push_back(zeros[i].second);
        return ans;
    
    }
};
