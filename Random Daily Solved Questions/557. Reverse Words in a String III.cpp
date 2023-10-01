class Solution {
public:
//     string reverseWords(string s) {
//         int index=0;
//         int start=0,end=0;
//         while(index<s.size()){
//             if(s[index]==' ' or index==s.size()-1)
//             {
//                 if(index==s.size()-1)
//                     reverse(s.begin()+start,s.end());
//                 else
//                     reverse(s.begin()+start,s.begin()+end);
//             start=++index;    
//             continue;
//             }
//             else{
//             end=++index;
                
//             }
            
//         }
//         return s;
//     }
    
string reverseWords(string s) {
        int n = s.length();
        int j=0;
        
        for(int i=0;i<=n;i++){
            if(s[i]==' '|| s[i]=='\0'){//s[i]=='\0' for last word//
                reverse(s.begin()+j,s.begin()+i);
                j=i+1;
            }
        }
        return s;
    }
};
