#include "../leetcode.h"

void dfs(vector<int> &values, TreeNode *node) {
    if (node == nullptr) return;
    dfs(values, node->left);
    values.push_back(node->val);
    dfs(values, node->right);
}

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b, ans;
        dfs(a, root1); 
        dfs(b, root2);
        int i = 0, j = 0;
        while (i < a.size() || j < b.size()) {
            if (i >= a.size()) ans.push_back(b[j++]);
            else if (j >= b.size()) ans.push_back(a[i++]);
            else {
                if (a[i] < b[j]) ans.push_back(a[i++]);
                else ans.push_back(b[j++]);
            }
        }

        return ans;
    }
};
