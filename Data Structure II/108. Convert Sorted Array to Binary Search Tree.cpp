/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// //Recurrsive 
// class Solution {
// public:
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         if(nums.size() == 0) return NULL;
//         if(nums.size() == 1)
//             return new TreeNode(nums[0]);
//         int mid =nums.size()/2;
//         TreeNode *root=new TreeNode(nums[mid]);
        
//         vector<int> leftV(nums.begin(),nums.begin()+mid);
//         vector<int> rightV(nums.begin()+mid+1,nums.end());
        
//         root->left=sortedArrayToBST(leftV);
//         root->right=sortedArrayToBST(rightV);
//         return root;
        
//     }
// };
    

//Iterative 
    struct Data
 {
     TreeNode *node;
     int l;
     int r;
     Data(int iL, int iR, vector<int> &num)
     {
         l = iL;
         r = iR;
         node = NULL;
         
         if (l>=r) return ;
         
         int mid = l + (r-l)/2;
         node = new TreeNode(num[mid]);
     }
 };
 
class Solution {
public:
    
    TreeNode *sortedArrayToBST(vector<int> &num) {
        stack<Data> s;
        
        Data root(0, num.size(), num);
        s.push(root);
        
        while (!s.empty()) 
        {
            Data pop = s.top(); s.pop();
        
            if (!pop.node) continue;
            
            int mid = pop.l + (pop.r - pop.l)/2;
            
            Data left(pop.l, mid, num);
            Data right(mid+1, pop.r, num);
            
            pop.node->left = left.node;
            pop.node->right = right.node;
            
            s.push(left);
            s.push(right);
        }
        
        return root.node;
    }
};
