class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> count;
        int answer=0;
        for(int num:nums){
            count[num]++;
            }
        for(auto it:count){
            if(it.second==1) return -1;
            answer+=ceil((double)it.second/3);
        }
        return answer;
        
//         // for(auto it : count)
//         //     cout<<it.first<<":"<<it.second<<endl;
//         for(auto it : count){
//             if(it.second==1) return -1;
//             int curr=0;
//             if(it.second%2==0){
//                 if(it.second>=6){
//                     answer+=(it.second/6)*2;
//                     it.second=it.second%6;
//                 }
//               if(it.second%3==0){
//                 if(it.second/3!=0){
//                 curr=it.second/3;
//                 answer+=curr;
//                 // cout<<it.first<<":"<<answer;
//                 if(it.second%3==2)
//                     answer++;
//                 else if(it.second%3==1)
//                     return -1;
//             }
//             }
//                 else{
//                     answer+=it.second/2;
//                 }
//             }
//             else{
//                 if(it.second/3!=0){
//                 curr=it.second/3;
//                 answer+=curr;
//                 // cout<<it.first<<":"<<answer;
//                 if(it.second%3==2)
//                     answer++;
//                 else if(it.second%3==1)
//                     answer++;
//             }
//             }
            
            
            
//             // ans+=(it.second&1)?(it.second-1/2)+1
//             // if(it.second==1)return -1;
//         }
//         return answer;
    }
};
