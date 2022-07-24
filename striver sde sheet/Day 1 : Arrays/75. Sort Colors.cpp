class Solution {
public:
//     void sortColors(vector<int>& nums) {
//         int count0=0,count1=0,count2=0;
//         for(auto c:nums){
//             if(c==0) count0++;
//             else if(c==1) count1++;
//             else count2++;
//         }
//             for(int i=0;i<nums.size();i++){
//                 if(count0){
//                    nums[i]=0;
//                    count0--;
                 
//                 } 
//                 else if(count1){
//                   nums[i]=1;
//                   count1--;
                  
//                 } 
//                 else 
//                     nums[i]=2;
//             }
          
        
//     }
    
// one pass in place solution
void sortColors(vector<int>& A) {
    int n=A.size();
    int n0 = -1, n1 = -1, n2 = -1;
    for (int i = 0; i < n; ++i) {
        if (A[i] == 0) 
        {
            A[++n2] = 2; A[++n1] = 1; A[++n0] = 0;
        }
        else if (A[i] == 1) 
        {
            A[++n2] = 2; A[++n1] = 1;
        }
        else if (A[i] == 2) 
        {
            A[++n2] = 2;
        }
    }
}
};
