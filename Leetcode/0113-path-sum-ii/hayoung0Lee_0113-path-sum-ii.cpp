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
public:
    vector<vector<int>> answer;
    vector<int> temp;
    
    void recursive(TreeNode* root, int targetSum, int currentSum){
        if(!root->left && !root->right){
            if(currentSum == targetSum){
                answer.push_back(temp);
            }
            return;
        }

        if(root->left){
            temp.push_back(root->left->val);
            recursive(root->left, targetSum, currentSum + root->left->val);
            temp.pop_back();
        }

        if(root->right){
            temp.push_back(root->right->val);
            recursive(root->right, targetSum, currentSum + root->right->val);
            temp.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return answer;
        }
        
        temp.push_back(root->val);
        recursive(root, targetSum, root->val);
        temp.pop_back();
        
        return answer;
    }
};