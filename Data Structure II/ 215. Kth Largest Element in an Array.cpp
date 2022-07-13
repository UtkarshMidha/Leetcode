class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        // return nums[nums.size()-k];
        //for(auto c:nums) cout<<c<<" ";
        
        
//         nth_element(nums.begin(), nums.begin() + k - 1, nums.end(),greater<int>());
//         return nums[k-1];
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};
