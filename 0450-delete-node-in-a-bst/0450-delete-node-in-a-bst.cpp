class Solution {
public:
    TreeNode* iop(TreeNode* root) {
        TreeNode* pred = root->left;

        while (pred->right) {
            pred = pred->right;
        }

        return pred;
    }

    TreeNode* ios(TreeNode* root) {
        TreeNode* suc = root->right;

        while (suc->left) {
            suc = suc->left;
        }

        return suc;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;

        if (root->val == key) {

            // No child
            if (!root->left && !root->right)
                return NULL;

            // One child
            if (!root->left)
                return root->right;

            if (!root->right)
                return root->left;

            // Two children
            TreeNode* pred = iop(root);
            root->val = pred->val;

            root->left = deleteNode(root->left, pred->val);
        }

        else if (root->val > key)
            root->left = deleteNode(root->left, key);

        else
            root->right = deleteNode(root->right, key);

        return root;
    }
};