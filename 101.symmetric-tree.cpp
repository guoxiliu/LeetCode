/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool checkSymmetric(TreeNode* leftNode, TreeNode* rightNode) {
        if (leftNode == NULL && rightNode == NULL)
            return true;
        if (leftNode == NULL || rightNode == NULL)
            return false;
        if (leftNode->val == rightNode->val)
            return checkSymmetric(leftNode->left, rightNode->right) && checkSymmetric(leftNode->right, rightNode->left);
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;

        return checkSymmetric(root->left, root->right);    
    }
};

