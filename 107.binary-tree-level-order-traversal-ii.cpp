/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    /*
        0. root
		1. for each level, find its children, push to a queue
		2. pop_front this level
		3. reverse res order
    */
        vector<vector<int>> res;
        if (root == NULL) return res;
        queue<TreeNode*> levelQueue;
        levelQueue.push(root);
        levelQueue.push(NULL);
        vector<int> levelVec;

        // Breadth-First Search
        while (!levelQueue.empty()) {
            TreeNode* head = levelQueue.front();
            levelQueue.pop();
            if (head == NULL) {
                res.push_back(levelVec);
                levelVec.clear();
                if (levelQueue.size() > 0) 
                    levelQueue.push(NULL);
            } else {
                levelVec.push_back(head->val);
                if (head->left) levelQueue.push(head->left);
                if (head->right) levelQueue.push(head->right);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

