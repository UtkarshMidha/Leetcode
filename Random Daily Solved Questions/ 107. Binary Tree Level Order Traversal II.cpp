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
class Solution {
private:
    
int findMaxLen(TreeNode* root){
    if(root==NULL) return 0;
    return 1+max(findMaxLen(root->left),findMaxLen(root->right));
}
    
    
void levelOrderRec(TreeNode* root, vector<vector<int>>& vec, int level){
    if(root==NULL) return;
    vec[level].push_back(root->val);
    levelOrderRec(root->left,vec,level-1);
    levelOrderRec(root->right,vec,level-1);
}
    
    
public:
    
    
// ----------------Reversing the level order-----------------    
//     vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
//         queue<TreeNode*> q;
//         vector<vector<int>> ans;
        
//         if(!root) return ans;
        
//         q.push(root);
        
//         while(!q.empty()){
//             int size=q.size();
//             vector<int> temp;
//             for(int i=0;i<size;i++){
                
//                 TreeNode* x=q.front();
//                 q.pop();
//                 temp.push_back(x->val);
//                 if(x->left)
//                     q.push(x->left);
//                 if(x->right)
//                     q.push(x->right);
//             }
//         ans.push_back(temp);
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
    

//-------------------Without reversing-----------------
vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int>> result;
    if(root==NULL) return result;
    int count = findMaxLen(root);
    for(int i = 0; i < count; i++)
    {
        vector<int> temp;
        result.push_back(temp);
    }
    levelOrderRec(root, result, count-1);
    return result;
}
};
