class Solution {
public:

    vector<int> ans;

    pair<int, bool> dfs(TreeNode* root) {

        if (root == nullptr)
            return {0, true};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // Check if both subtrees are perfect
        if (left.second && right.second && left.first == right.first) {

            int height = left.first + 1;

            int size = (1 << height) - 1;

            ans.push_back(size);

            return {height, true};
        }

        return {0, false};
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {

        dfs(root);

        sort(ans.begin(), ans.end(), greater<int>());

        if (ans.size() < k)
            return -1;

        return ans[k - 1];
    }
};