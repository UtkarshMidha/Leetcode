class Solution {
public:
    int minDeletions(string s) {
        vector<int> frequency(26, 0);
        for (auto  c : s) 
            frequency[c - 'a']++;
        int deleteCount = 0;
        unordered_set<int> mp;
        for (int i = 0; i < 26; i++)
        {while (frequency[i] && mp.find(frequency[i]) != mp.end()) {
                frequency[i]--;
                deleteCount++;
            }
            mp.insert(frequency[i]);
        }
        return deleteCount;
        
        // TO DO : Check and write better approach
    }
};
