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

    struct T {
        bool isBST;
        int max;
        int min;
        int sum;

        T(bool isBST = false, int max = 0, int min = 0, int sum = 0)
            : isBST(isBST), max(max), min(min), sum(sum) {}
    };

    T Traverse(TreeNode* root, int& ans) {

        if (root == nullptr)
            return T(true, INT_MIN, INT_MAX, 0);

        T left = Traverse(root->left, ans);
        T right = Traverse(root->right, ans);

        if (!left.isBST || !right.isBST)
            return T();

        if (root->val <= left.max || root->val >= right.min)
            return T();

        int sum = root->val + left.sum + right.sum;

        ans = max(ans, sum);

        return T(
            true,
            max(root->val, right.max),
            min(root->val, left.min),
            sum
        );
    }

    int maxSumBST(TreeNode* root) {

        int ans = 0;

        Traverse(root, ans);

        return ans;
    }
};