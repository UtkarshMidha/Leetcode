class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> stk;
        for(int i=s.size()-1;i>=0;i--){
        if(s[i]==')') stk.push({s[i],i});     
        if(s[i]=='(')
            stk.size() and stk.top().first==')'? stk.pop(): stk.push({s[i],i});           
    }
        string ans="";  ans.reserve(s.size());
    for(int i=0;i<s.size();i++)  
        if(stk.size() and stk.top().second==i) stk.pop();   else ans+= s[i];
     
    return ans;
        
        
        
    }
};
