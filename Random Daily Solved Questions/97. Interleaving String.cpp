class Solution {
private:
    //------Recurrsion---------
    bool recursion(string &s1,int i,string &s2,int j,string &s3,string s){
        if(i== s1.size() and j== s2.size() and s==s3) return true;
        bool ans=false;
        if(i<size(s1))
            ans|=recursion(s1,i+1,s2,j,s3,s+s1[i]);
        if(j<size(s2))
            ans|=recursion(s1,i,s2,j+1,s3,s+s2[j]);
        return ans;
    }
    
    
    // ---------Recuursion + memorization ---------
    vector<vector<bool>> dp;
    bool solve(int i, int j, int k, string t, string s1, string s2, string s3)
    {
        if (i > s1.size() || j > s2.size() || k > s3.size())
            return false;
        if (i + j > k)
            return false;
        if (i + j == k)
        {
            if (t == s3)
                return true;
        }
        dp[i][j] = true;
        int c1 = false, c2 = false;
        if (i < s1.size() && !dp[i + 1][j] && s1[i] == s3[k])
        {
            c1 = solve(i + 1, j, k + 1, t + s1[i], s1, s2, s3);
        }
        if (j < s2.size() && !dp[i][j + 1] && s2[j] == s3[k])
        {
            c2 = solve(i, j + 1, k + 1, t + s2[j], s1, s2, s3);
        }
        return c1 || c2;
    }
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        // if(size(s1)+size(s2)!=size(s3)) return false;
        // return recursion(s1,0,s2,0,s3,"");
        
        
        
        // int n = s1.size(), m = s2.size(), o = s3.size();
        // if (n + m != o)
        //     return false;
        // if (s1 == s3)
        //     return true;
        // if (s2 == s3)
        //     return true;
        // dp.resize(n + 1, vector<bool>(m + 1, false));
        // bool res = solve(0, 0, 0, "", s1, s2, s3);
        // return res;
        //--------------------------DP---------------------
        if(s3.length() != s1.length() + s2.length())
        return false;
    
    bool table[s1.length()+1][s2.length()+1];
    
    for(int i=0; i<s1.length()+1; i++)
        for(int j=0; j< s2.length()+1; j++){
            if(i==0 && j==0)
                table[i][j] = true;
            else if(i == 0)
                table[i][j] = ( table[i][j-1] && s2[j-1] == s3[i+j-1]);
            else if(j == 0)
                table[i][j] = ( table[i-1][j] && s1[i-1] == s3[i+j-1]);
            else
                table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1] ) || (table[i][j-1] && s2[j-1] == s3[i+j-1] );
        }
        
    return table[s1.length()][s2.length()];
        
    }
};
