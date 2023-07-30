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
    int ans;
    
    void helper(TreeNode* root, long long int targetSum){
        if(!root){
            return;
        }
        
        if(root->val == targetSum){
            // targetSum에 매번 빼줘서 똑같아지면 다 된것
            ans++; // 그리고 뒤에 더있을수도 있어서 return 아님
        }
        
        helper(root->left, targetSum-(root->val)); // 여기서 빼줌
        helper(root->right, targetSum-(root->val));
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return ans;
        }
        
        helper(root, targetSum); // from root
        
        pathSum(root->left, targetSum); // new root;
        
        pathSum(root->right, targetSum); // new root
        
        return ans;
    }
};