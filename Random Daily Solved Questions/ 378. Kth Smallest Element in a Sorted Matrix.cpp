class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // //------------Time: O(M * N)------------
        // // -----------O(N^2) space--------------
        // //-------------SORTING------------------
        // vector<int> ans;
        // for(int i=0;i<matrix.size();i++)
        //     for(int j=0;j<matrix[0].size();j++)
        //         ans.push_back(matrix[i][j]);
        // sort(ans.begin(),ans.end());
        // return ans[k-1];
        
        
        // //------Time: O(M * N * logK)----------
        // //---------------O(K) space------------
        // //--------------MAX HEAP---------------
        // priority_queue<int>pq;
        // for(int i=0;i<matrix.size();i++)
        //     for(int j=0;j<matrix[0].size();j++){
        //         if(pq.size()<k)
        //             pq.push(matrix[i][j]);
        //         else if(pq.top()>matrix[i][j]){
        //             pq.pop();
        //             pq.push(matrix[i][j]);
        //         }
        //     }
        // return pq.top();
        
        
        
        // //------Time: O(K * logK)--------------
        // //---------------O(K) space------------
        // //--------------MIN HEAP---------------
//         priority_queue<vector<int>,vector<vector<int>>,greater<>> min_heap;
//         int m=matrix.size(),n=matrix[0].size(),ans=INT_MIN;
//         for(int r=0;r<min(m,k);r++)
//             min_heap.push({matrix[r][0],r,0});
        
//         for(int i=1;i<=k;i++){
//             auto top=min_heap.top();
//             min_heap.pop();
//             ans=top[0];
//             int r=top[1];
//             int c=top[2];
            
//             if(c+1<n)
//                 min_heap.push({matrix[r][c+1],r,c+1});
//         }
//         return ans;
        
        
        //------------Time: O(N*N)--------------
        //------------O(1) Space---------------- 
        // -------------BINARY SEARCH-----------
        int rows = matrix.size(), cols = matrix[0].size();
        int low = matrix[0][0], high = matrix[rows - 1][cols - 1] ;
        while(low<=high){
            int mid=low+(high-low)/2;
            int count=0,ans=low;
            for(int r=0,c=cols-1;r<rows;r++){
                while(c>=0 and matrix[r][c]>mid) c--;
                if(c<0) break;
                else{
                    count+=(c+1);
                    ans=max(ans,matrix[r][c]);
                }
             }
            if(count==k) return ans;
            else if(count<k) low=mid+1;
            else high=mid-1;
            
        }
        return low;
    }
};
