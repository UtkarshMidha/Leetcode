class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for(auto i:s){
            if(i=='(' || i=='{' || i=='[')
                ss.push(i);
            else{
                if( ss.empty() || (ss.top()=='(' && i!=')' ) || (ss.top()=='[' && i!=']') || ss.top()=='{' && i!='}' )
                return false;
        ss.pop();
            }
        }
        return ss.empty();
    }
};
