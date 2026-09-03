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

    // Step 1: Store BST elements in sorted order
    void inorder(TreeNode* root, vector<int>& nums) {
        if (root == nullptr)
            return;

        inorder(root->left, nums);

        nums.push_back(root->val);

        inorder(root->right, nums);
    }

    // Step 2: Build a balanced BST from sorted array
    TreeNode* buildBST(vector<int>& nums, int left, int right) {

        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = buildBST(nums, left, mid - 1);

        root->right = buildBST(nums, mid + 1, right);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {

        vector<int> nums;

        // Get sorted elements
        inorder(root, nums);

        // Build balanced BST
        return buildBST(nums, 0, nums.size() - 1);
    }
};

