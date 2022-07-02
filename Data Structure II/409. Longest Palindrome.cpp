class Solution {
public:
    int longestPalindrome(string s) {
      //Count the number of odd occuring characters if more than 1 then one of those odd can be used as the center of the palindrome
        int odds = 0;
        for (char c='A'; c<='z'; c++)
            odds += count(s.begin(), s.end(), c) & 1;
        return s.size() - odds + (odds > 0);
    }
};
