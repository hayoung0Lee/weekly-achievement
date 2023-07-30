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
    bool found = false;
    
    void recursive(TreeNode* root, int targetSum, int currentSum){
        if(!root->left && !root->right){
            if(currentSum == targetSum){
                found = true;
            }
            return;
        }
        
        if(root->left){
            recursive(root->left, targetSum, currentSum + root->left->val);
        }
        
        if(root->right){
            recursive(root->right, targetSum, currentSum + root->right->val);
        }
    }
    
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        
        recursive(root, targetSum, root->val);
        
        if(found){
            return true;
        }
        return false;
    }
};