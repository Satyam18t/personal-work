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

    TreeNode* current;

    void Inorder(TreeNode* root) {

        if (root == nullptr)
            return;

        Inorder(root->left);

        current->right = root;
        root->left = nullptr;
        current = root;

        Inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {

        TreeNode* dummy = new TreeNode(0);

        current = dummy;

        Inorder(root);

        return dummy->right;
    }
};