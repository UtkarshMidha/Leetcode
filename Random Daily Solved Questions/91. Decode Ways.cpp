class Solution {
public:
    //Recursive || Time Complexity - Exponential
    int helper(string &s,int i)
    {
        //base case
        if(i==s.length())return 1;
        if(i>s.length())return 0;
        
        string x="";
        x+=s[i];
        //single "0" doesnot map to any letter
        if(x=="0")return 0;
        int temp1=0,temp2=0;
        
        //if string is between "1" to "9"
        if(stoi(x)<=9)
        {
            temp1=helper(s,i+1);
        }
        
        if(i+1<s.length())
        {
            string y=x+s[i+1];
            
            //if string is between "10" to "26"
            if(stoi(y)<=26)
            {
                temp2=helper(s,i+2);
            }
        }
        return temp1+temp2;
        
    }
    
    //Top Down DP || Time Complexity - O(N) || Space Complexity : O(N)
    int helperDP(string &s,int i,vector<int> &dp)
    {
        if(i==s.length())return 1;
        if(i>s.length())return 0;
        if(dp[i]!=-1)return dp[i];
        
        string x="";
        x+=s[i];

        if(x=="0")return 0;
        int temp1=0,temp2=0;
        if(stoi(x)<=9)
        {
            temp1=helperDP(s,i+1,dp);
        }
        
        if(i+1<s.length())
        {
            string y=x+s[i+1];
            
            if(stoi(y)<=26)
            {
                temp2=helperDP(s,i+2,dp);
            }
        }

        return dp[i]=temp1+temp2;
        
    }
    
    //Bottom Up DP (Iterative) || Time Complexity - O(N) || Space Complexity : O(N)
    int helperTab(string s)
    {
        vector<int>dp(s.length()+1,0);
        
        dp[s.length()]=1;
        
        for(int i=s.length()-1;i>=0;i--)
        {
            string x="";
            x+=s[i];
            if(x=="0")continue;
            int temp1=0,temp2=0;
            if(stoi(x)<=9)
            {
                temp1=dp[i+1];
            }

            if(i+1<s.length())
            {
                string y=x+s[i+1];

                if(stoi(y)<=26)
                {
                    temp2=dp[i+2];
                }
            }

            dp[i]=temp1+temp2;
        }
        
        return dp[0];
    }
    
    //Space Optimised Bottom Up || Time Complexity - O(N) || Space Complexity : O(1)
    int helperTabOP(string s)
    {
        
        int next=1,cur=0,next2=0;
        string x="",y;
        for(int i=s.length()-1;i>=0;i--)
        {
            x="";
            x+=s[i];
            if(x=="0")
            {
                next2=next;
                next=0;
                cur=0;
                continue;
            }
            int temp1=0,temp2=0;
            if(stoi(x)<=9)
            {
                temp1=next;
            }

            if(i+1<s.length())
            {
                y=x+s[i+1];

                if(stoi(y)<=26)
                {
                    temp2=next2;
                }
            }
            cur=temp1+temp2;
            next2=next;
            next=cur;
        }
        
        return cur;
    }
    
    
    
    int numDecodings(string s) {
        
        //Recursive 
        // return helper(s,0);
        
        //Top Down
        // vector<int>dp(s.length()+1,-1);
        //return helperDP(s,0,dp)
        
        //Bottom Up
        //return helperTab(s);
        
        //Space Optimised
        return helperTabOP(s);
        
    }
};
