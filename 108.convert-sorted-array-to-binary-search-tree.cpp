/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size()-1);   
    }

    TreeNode* buildBST(vector<int>& nums, int low, int high) {
        if (low > high) return NULL;
        int mid = low + (high-low) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildBST(nums, low, mid-1);
        node->right = buildBST(nums, mid+1, high);
        return node;
    }
};

