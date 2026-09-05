class Solution {
public:
    TreeNode* trim(TreeNode* root,int low,int high){
        if (root == NULL) return NULL;

        if (root->val < low)
            return trim(root->right, low, high);

        if (root->val > high)
            return trim(root->left, low, high);

        root->left = trim(root->left, low, high);
        root->right = trim(root->right, low, high);

        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return trim(root,low,high);
    }
};