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
    TreeNode* solver(vector<int>& inorder, vector<int>& postorder,int &root_idx,int left,int right){
        if(left>right) return NULL;
        int pivot=left;
        while(inorder[pivot]!=postorder[root_idx])
            pivot++;
        TreeNode* node=new TreeNode(postorder[root_idx]);
        root_idx--;
        node->right=solver(inorder,postorder,root_idx,pivot+1,right);
        node->left=solver(inorder,postorder,root_idx,left,pivot-1);
        return node;
        
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int root_idx=postorder.size()-1;
        return solver(inorder,postorder,root_idx,0,postorder.size()-1);
    }
};
