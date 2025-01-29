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
    // Function to check if a binary tree is symmetric.
    // A tree is symmetric if its left and right subtrees are mirror images of each other.
    bool isSymmetric(TreeNode* root) {
        // If the root is null, the tree is symmetric by definition.
        if (!root) return true;

        // Call the helper function `isMirror` to check if the left and right subtrees are mirrors.
        return isMirror(root->left, root->right);
    }

private:
    // Helper function to check if two subtrees (n1 and n2) are mirror images of each other.
    bool isMirror(TreeNode* n1, TreeNode* n2) {
        // Case 1: Both nodes are null, meaning we've reached the leaf nodes of both subtrees.
        // In this case, they are symmetric.
        if (n1 == NULL && n2 == NULL) {
            return true;
        }

        // Case 2: If one of the nodes is null and the other is not, the subtrees are not symmetric.
        if (n1 == NULL || n2 == NULL) {
            return false;
        }

        // Case 3: Check if the values of the current nodes are the same.
        // If they are not the same, the subtrees are not symmetric.
        if (n1->val != n2->val) {
            return false;
        }

        // Recursive case:
        // Check two conditions:
        // 1. The left subtree of n1 must be a mirror of the right subtree of n2.
        bool leftMirror = isMirror(n1->left, n2->right);

        // 2. The right subtree of n1 must be a mirror of the left subtree of n2.
        bool rightMirror = isMirror(n1->right, n2->left);

        // The subtrees are mirrors if both conditions are true.
        return leftMirror && rightMirror;
    }
};