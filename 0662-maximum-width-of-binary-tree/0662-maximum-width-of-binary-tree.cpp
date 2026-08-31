class Solution {
public:
    void solve(TreeNode* root, int level, unsigned long long index,
               vector<unsigned long long>& first, int& maxx) {
        
        if (root == NULL)
            return;

        if (level == first.size()) {
            first.push_back(index);
        }

        maxx = max(maxx, (int)(index - first[level] + 1));

        solve(root->left, level + 1, index * 2, first, maxx);
        solve(root->right, level + 1, index * 2 + 1, first, maxx);
    }

    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        vector<unsigned long long> first;
        int maxx = 0;

        solve(root, 0, 0, first, maxx);

        return maxx;
    }
};