/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (41.44%)
 * Likes:    977
 * Dislikes: 35
 * Total Accepted:    244.6K
 * Total Submissions: 589.7K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 * 
 * 
 * Return:
 * 
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
 * 
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
    void findPath(vector<vector<int>>& res, vector<int>& cur, TreeNode* root, int sum) {
        if(root == NULL) return;

        cur.push_back(root->val);
        int newsum = sum - root->val;

        // see if current node is a leaf node
        if(root->left == NULL && root->right == NULL && newsum == 0) {
            res.push_back(cur);
        }
        findPath(res, cur, root->left, newsum);
        findPath(res, cur, root->right, newsum);

        cur.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> tmp;
        findPath(res, tmp, root, sum);
        return res;
    }
};

