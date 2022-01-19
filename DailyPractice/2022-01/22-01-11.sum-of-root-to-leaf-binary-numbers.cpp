#include "../leetcode.h"

class Solution {
    int ans;
public:
    void dfs(TreeNode *node, int cur) {
        int tmp = cur * 2 + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            ans += tmp;
            return;
        }
        if (node->left) dfs(node->left, tmp);
        if (node->right) dfs(node->right, tmp);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        ans = 0;
        if (root == nullptr) return 0;
        dfs(root, 0);
        return ans;
    }
};

