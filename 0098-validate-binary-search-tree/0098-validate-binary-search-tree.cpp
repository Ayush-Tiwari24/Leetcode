class Solution {
public:
    bool flag = true;
    TreeNode* prev = NULL;

    void inorder(TreeNode* curr) {
        if (curr == NULL) return;

        inorder(curr->left);

        if (prev != NULL && curr->val <= prev->val) {
            flag = false;
            return;
        }

        prev = curr;

        inorder(curr->right);
    }

    bool isValidBST(TreeNode* root) {
        inorder(root);
        return flag;
    }
};