/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (40.19%)
 * Likes:    939
 * Dislikes: 20
 * Total Accepted:    161.5K
 * Total Submissions: 401.7K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    int postIndex;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, unordered_map<int, int>& pos) {
        if(inStart > inEnd) return NULL;

        // the end of the postorder traversal is the root node
        TreeNode *root = new TreeNode(postorder[postIndex--]);

        // if the node has no children then return
        if(inStart == inEnd) 
            return root;

        int inIndex = pos[root->val];
        root->right = buildTree(inorder, postorder, inIndex+1, inEnd, pos);
        root->left = buildTree(inorder, postorder, inStart, inIndex-1, pos);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) 
            return NULL;
        unordered_map<int, int> pos;
        int n = inorder.size();
        postIndex = n - 1;
        for(int i = 0; i < n; i++) {
            pos[inorder[i]] = i;
        }
        return buildTree(inorder, postorder, 0, n-1, pos);
    }
};

