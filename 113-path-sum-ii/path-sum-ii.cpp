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
    void findPath(TreeNode* root, vector<vector<int>>& ans, vector<int> temp, int target, int value) {
        if(!root) return;
        value += root->val;
        temp.push_back(root->val);
        if(!root->left && !root->right && value == target) ans.push_back(temp);
        findPath(root->right, ans, temp, target, value);
        findPath(root->left, ans, temp, target, value);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        findPath(root, ans, temp, targetSum, 0);
        return ans;
    }
};