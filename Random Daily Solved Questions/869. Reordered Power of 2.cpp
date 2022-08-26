class Solution {

    
private:
    string sorted_num(int n) {
        string res = to_string(n);
        sort(res.begin(), res.end());
        return res;
    }
public:
    bool reorderedPowerOf2(int n) {
//         set<int>s;
//         for(int i=0; i<31; i++)
//         {
//             s.insert(pow(2,i));
//         }
        
//         if(s.find(n)!=s.end())
//             return true;
        
//         vector<int>digit;
//         while(n>0)
//         {
//             digit.push_back(n%10);
//             n=n/10;
//         }
        
//         sort(digit.begin(),digit.end());
        
//         do{
//             if(digit[0]==0)
//                 continue;
//             else
//             {
//                 int ans=0;
//                 for(int i=0; i<digit.size(); i++)
//                 {
//                     ans=ans*10+digit[i];
//                 }
                
//                 if(s.find(ans)!=s.end())
//                     return true;
//             }
//         }while(next_permutation(digit.begin(),digit.end()));
        
//         return false;

    string N_str = sorted_num(n);
        for (int i = 0; i < 32; i++)
            if (N_str == sorted_num(1 << i)) return true;
        return false;
    
    }
};
