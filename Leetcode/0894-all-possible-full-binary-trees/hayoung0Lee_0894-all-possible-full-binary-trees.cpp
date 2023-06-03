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
    vector<TreeNode*> allPossibleFBT(int n) {
        // https://leetcode.com/problems/all-possible-full-binary-trees/discuss/618779/Python-3-solution-(Recursion-Memoization-DP)-with-explantions
        // memoization
        unordered_map<int, vector<TreeNode*>> memo;
        return generateTrees(n, memo); 
    }
    
    vector<TreeNode*> generateTrees(int n, unordered_map<int, vector<TreeNode*>>& memo){
        if(memo.count(n))
            return memo[n];
        
        vector<TreeNode*> ans;

        if (n % 2 == 0)
            return ans;

        if (n == 1) {
            ans.push_back(new TreeNode(0));
            return ans;
        }
        
        for(int i = 1; i < n; i+= 2){
            vector<TreeNode*> leftTrees = generateTrees(i, memo);
            vector<TreeNode*> rightTrees = generateTrees(n - i - 1, memo);
            
            for(auto left : leftTrees){
                for(auto right : rightTrees){
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }
        
        memo[n] = ans;
        return ans;
    }
};