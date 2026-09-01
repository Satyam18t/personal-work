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

    int solve(TreeNode* root, int curnum) {
        if (root == nullptr)
            return 0;

        curnum = curnum * 10 + root->val;

        // Leaf node
        if (root->left == nullptr && root->right == nullptr)
            return curnum;

        return solve(root->left, curnum) + solve(root->right, curnum);
    }

    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};