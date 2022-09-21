class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
//         vector<int> sum;
//         for(vector<int> q:queries){
//             nums[q[1]]+=q[0];
//             int ans=0;
//             for(int i=0;i<nums.size();i++)
//                 if(nums[i]%2==0)
//                     ans+=nums[i];
//             sum.push_back(ans);
            
//         }
//         return sum;
        
        
        vector<int> res={};
        int sum = accumulate(begin(nums), end(nums), 0, [](int curr_sum, int curr_val) {
            return curr_sum + (curr_val % 2 == 0 ? curr_val : 0); });
  for (auto &q : queries) {
    if (nums[q[1]] % 2 == 0) sum -= nums[q[1]];
    nums[q[1]] += q[0];
    if (nums[q[1]] % 2 == 0) sum += nums[q[1]];
    res.push_back(sum);
  }
  return res;
    }
};
