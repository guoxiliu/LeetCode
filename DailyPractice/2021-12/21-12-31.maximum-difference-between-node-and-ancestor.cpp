#include "../leetcode.h"

class Solution {
public: 
    int maxAncestorDiff(TreeNode *root, int cur_min=INT_MAX, int cur_max=INT_MIN) {
        if (root == nullptr) return cur_max-cur_min;
        cur_min = min(cur_min, root->val);
        cur_max = max(cur_max, root->val);
        return max(maxAncestorDiff(root->left, cur_min, cur_max), 
                   maxAncestorDiff(root->right, cur_min, cur_max));
    }
    
};
