class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1,j=b.size()-1,carry=0;
        string res="";
        while(i>=0||j>=0||carry){
            if(i>=0 && a[i--]=='1') ++carry;
            if(j>=0 && b[j--]=='1') ++carry;
            res.insert(0,1,carry%2==1?'1':'0');
            carry/=2;
        }
        return res;
    }
};
