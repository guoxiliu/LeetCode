/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (42.16%)
 * Likes:    1863
 * Dislikes: 52
 * Total Accepted:    238.7K
 * Total Submissions: 566.1K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
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
    int preIndex;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& pos) {
        if(inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preIndex++]);

        // if this node has no children then return
        if(inStart == inEnd)
            return root;

        // find the index of this node in inorder vector
        int inIndex = pos[root->val];
        
        // recursively construct the left and right subtree
        root->left = buildTree(preorder, inorder, inStart, inIndex-1, pos);
        root->right = buildTree(preorder, inorder, inIndex+1, inEnd, pos);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> pos;
        for(int i = 0; i < inorder.size(); i++) {
            pos[inorder[i]] = i;
        }
        preIndex = 0;
        return buildTree(preorder, inorder, 0, inorder.size()-1, pos);
    }
};

