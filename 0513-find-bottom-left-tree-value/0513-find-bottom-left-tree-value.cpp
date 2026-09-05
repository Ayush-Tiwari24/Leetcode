class Solution {
public:
    int level(TreeNode* root){
        if(root==NULL)return 0;
        return 1+max(level(root->left),level(root->right));
    }
    void nthLevel(TreeNode* root, int curr, int level, vector<int>& v) {
    if (root == NULL)return;
    if (curr == level) {
        v.push_back(root->val);
        return;
    }
    nthLevel(root->left, curr + 1, level, v);
    nthLevel(root->right, curr + 1, level, v);
}
    int lOrder(TreeNode* root,int ans) {
        int n = level(root);
        for (int i = 1; i <= n; i++) {
            vector<int> v;
            nthLevel(root, 1, i, v);
            ans=v[0];
        }
        return ans;
    }
    int findBottomLeftValue(TreeNode* root) {
        int ans;
        return lOrder(root,ans);
    }
};