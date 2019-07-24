/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (46.58%)
 * Likes:    944
 * Dislikes: 71
 * Total Accepted:    235.8K
 * Total Submissions: 506.2K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    void findPath(TreeNode* node, string path, vector<string> &paths) {
        if(node == NULL) return;
        path.append(to_string(node->val));
        if(node->left == NULL && node->right == NULL) {
            paths.push_back(path);
        } else {
            path.append("->");
            findPath(node->left, path, paths);
            findPath(node->right, path, paths);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return vector<string>{};
        vector<string> res;
        findPath(root, "", res);
        return res;
    }
};

