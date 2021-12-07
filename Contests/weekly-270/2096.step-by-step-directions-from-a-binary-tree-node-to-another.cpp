/*
 * @lc app=leetcode id=2096 lang=cpp
 *
 * [2096] Step-By-Step Directions From a Binary Tree Node to Another
 *
 * https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/
 *
 * algorithms
 * Medium (39.21%)
 * Likes:    133
 * Dislikes: 18
 * Total Accepted:    4.1K
 * Total Submissions: 10.4K
 * Testcase Example:  '[5,1,2,3,null,6,4]\n3\n6'
 *
 * You are given the root of a binary tree with n nodes. Each node is uniquely
 * assigned a value from 1 to n. You are also given an integer startValue
 * representing the value of the start node s, and a different integer
 * destValue representing the value of the destination node t.
 * 
 * Find the shortest path starting from node s and ending at node t. Generate
 * step-by-step directions of such path as a string consisting of only the
 * uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific
 * direction:
 * 
 * 
 * 'L' means to go from a node to its left child node.
 * 'R' means to go from a node to its right child node.
 * 'U' means to go from a node to its parent node.
 * 
 * 
 * Return the step-by-step directions of the shortest path from node s to node
 * t.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
 * Output: "UURL"
 * Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [2,1], startValue = 2, destValue = 1
 * Output: "L"
 * Explanation: The shortest path is: 2 → 1.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is n.
 * 2 <= n <= 10^5
 * 1 <= Node.val <= n
 * All the values in the tree are unique.
 * 1 <= startValue, destValue <= n
 * startValue != destValue
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, TreeNode*> par;
    unordered_set<TreeNode*> visited;
    
public:
    // A recurise approach to find the path from the start node to destination node.
    bool findPath(TreeNode *s, TreeNode *e, string &cur) {
        if (s == e) return true;
        
        if (s->left != nullptr && visited.find(s->left) == visited.end()) {
            cur.push_back('L');
            visited.insert(s->left);
            if(findPath(s->left, e, cur)) return true;
            cur.pop_back();
        }

        if (s->right != nullptr && visited.find(s->right) == visited.end()) {
            cur.push_back('R');
            visited.insert(s->right);
            if(findPath(s->right, e, cur)) return true;
            cur.pop_back();
        }

        if (par[s] != nullptr && visited.find(par[s]) == visited.end()) {
            cur.push_back('U');
            visited.insert(par[s]);
            if(findPath(par[s], e, cur)) return true;
            cur.pop_back();
        }

        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        if (root == nullptr) return "";
        par[root] = nullptr;
        TreeNode *start = nullptr, *dest = nullptr;
        // Find the start and destination nodes, and the parent node of each node.
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *curr = st.top();
            if (curr->val == startValue) start = curr;
            else if (curr->val == destValue) dest = curr;
            st.pop();
            if (curr->left) {
                par[curr->left] = curr;
                st.push(curr->left);
            }
            if (curr->right) {
                par[curr->right] = curr;
                st.push(curr->right);
            }
        }
        
        string ans = "";
        visited.insert(start);
        if(findPath(start, dest, ans)) {
            return ans;
        }
        return "";
    }
};
// @lc code=end

