class Solution {
public:
    string addStrings(string num1, string num2) {
       string ans="";
        int carry=0;
        int i=num1.size()-1,j=num2.size()-1;
        while(i>=0 || j>=0){
            if(i>=0) carry+=num1[i--]-'0';
            if(j>=0) carry+=num2[j--]-'0';
            ans=to_string(carry%10)+ans;
            carry/=10;
        }
           return carry?"1"+ans:ans;
    }
};
