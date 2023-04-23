class Solution {
public:
    int numberOfArrays(string s, int k) {
    int s_sz = s.size(), dp_sz = to_string(k).size() + 1;
    vector<int> dp(dp_sz);
    dp[s_sz % dp_sz] = 1;
    for (int i = s_sz - 1; i >= 0; --i) {
        dp[i % dp_sz] = 0;
        if (s[i] == '0')
            continue;
        for (long sz = 1, n = 0; i + sz <= s_sz; ++sz) {
            n = n * 10 + s[i + sz - 1] - '0';
            if (n > k)
                break;
            dp[i % dp_sz] = (dp[i % dp_sz] + dp[(i + sz) % dp_sz]) % 1000000007;
        }
    }
    return dp[0];
    }
        
    
};
