int level(TreeNode* root) {
    if (root == NULL)
        return 0;

    return 1 + max(level(root->left), level(root->right));
}

void nthLevel(TreeNode* root, int curr, int level, int& maxi) {
    if (root == NULL)
        return;

    if (curr == level) {
        maxi = max(maxi, root->val);
        return;
    }

    nthLevel(root->left, curr + 1, level, maxi);
    nthLevel(root->right, curr + 1, level, maxi);
}

void lOrder(TreeNode* root, vector<int>& ans) {
    int n = level(root);

    for (int i = 1; i <= n; i++) {
        int maxi = INT_MIN;

        nthLevel(root, 1, i, maxi);

        ans.push_back(maxi);
    }
}

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;

        lOrder(root, ans);

        return ans;
    }
};