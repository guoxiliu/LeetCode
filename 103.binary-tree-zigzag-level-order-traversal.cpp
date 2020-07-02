/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (42.49%)
 * Likes:    1060
 * Dislikes: 62
 * Total Accepted:    234.6K
 * Total Submissions: 552.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};

        vector<vector<int>> res;
        queue<TreeNode*> nodeQ;
        nodeQ.push(root);
        nodeQ.push(NULL);
        vector<int> row;
        bool zigzag = false;

        while(!nodeQ.empty()) {
            TreeNode* front = nodeQ.front();
            nodeQ.pop();
            if(front == NULL) {
                if(zigzag) reverse(row.begin(), row.end());
                res.push_back(row);
                row = {};
                zigzag = !zigzag;
                if(!nodeQ.empty()) nodeQ.push(NULL);
            } else {
                row.push_back(front->val);
                if(front->left) nodeQ.push(front->left);
                if(front->right) nodeQ.push(front->right);
            }
        }

        return res;
    }
};

