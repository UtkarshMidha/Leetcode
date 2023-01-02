// class Solution {
// public:
//     bool detectCapitalUse(string word) {
//             if(word.size()==1) return true;
//             if(word[0]>='a' && word[0]<='z')
//                 goto label_1;
//             else if(word[0]>='A' && word[0]<='Z')
//                     goto label_2;
//             else return false;
//         label_1:{
//             for(int i=1;i<word.size();i++)
//                 if(word[i]<'a' || word[i]>'z')
//                     return false;
//         return true;
//         }
        
//         label_2:{
//             bool flag=false,flag1=false;
//             for(int i=1;i<word.size();i++){
//                 if(word[i]<'a' || word[i]>'z'){
//                  flag=false; break;   
//                 }
//                    else flag=true;
                 
//             }
//            for(int i=1;i<word.size();i++){
//                 if(word[i]<'A' || word[i]>'Z'){
//                     flag1=false;  break;
//                 }
//                 else    flag1=true;
                 
//            }
            
//             return (flag|flag1);
//         }
        
        
        
//     }
// };



class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt=0;
        int loc;
        for(int i=0;i<word.length();i++){
            if(word[i]>='A' && word[i]<='Z'){
                cnt++;
                loc = i;
            }
        }
        return cnt == word.length() || cnt == 0 || (cnt==1 && loc==0);
            }
};
