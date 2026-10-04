class Solution {
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        if(root == NULL) return;

        if(root->left)
            parent[root->left] = root;

        if(root->right)
            parent[root->right] = root;

        markParent(root->left, parent);
        markParent(root->right, parent);
    }

    TreeNode* find(TreeNode* root, int start) {
        if(root == NULL) return NULL;

        if(root->val == start)
            return root;

        TreeNode* left = find(root->left, start);
        if(left != NULL)
            return left;

        TreeNode* right = find(root->right, start);
        if(right != NULL)
            return right;

        return NULL;
    }

    int amountOfTime(TreeNode* root, int start) {
        TreeNode* first = find(root, start);

        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root, parent);

        unordered_set<TreeNode*> s;
        s.insert(first);

        queue<pair<TreeNode*, int>> q;
        q.push({first, 0});

        int ans = 0;

        while(q.size() > 0) {
            pair<TreeNode*, int> p = q.front();
            q.pop();

            TreeNode* temp = p.first;
            int level = p.second;

            ans = max(ans, level);

            if(temp->left && s.find(temp->left) == s.end()) {
                q.push({temp->left, level + 1});
                s.insert(temp->left);
            }

            if(temp->right && s.find(temp->right) == s.end()) {
                q.push({temp->right, level + 1});
                s.insert(temp->right);
            }

            if(parent.find(temp) != parent.end()) {
                if(s.find(parent[temp]) == s.end()) {
                    q.push({parent[temp], level + 1});
                    s.insert(parent[temp]);
                }
            }
        }

        return ans;
    }
};