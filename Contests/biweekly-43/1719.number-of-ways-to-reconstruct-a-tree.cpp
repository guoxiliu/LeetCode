/*
 * @lc app=leetcode id=1719 lang=cpp
 *
 * [1719] Number Of Ways To Reconstruct A Tree
 *
 * https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/description/
 *
 * algorithms
 * Hard (40.60%)
 * Likes:    99
 * Dislikes: 73
 * Total Accepted:    2.1K
 * Total Submissions: 5.1K
 * Testcase Example:  '[[1,2],[2,3]]'
 *
 * You are given an array pairs, where pairs[i] = [xi, yi], and:
 * 
 * 
 * There are no duplicates.
 * xi < yi
 * 
 * 
 * Let ways be the number of rooted trees that satisfy the following
 * conditions:
 * 
 * 
 * The tree consists of nodes whose values appeared in pairs.
 * A pair [xi, yi] exists in pairs if and only if xi is an ancestor of yi or yi
 * is an ancestor of xi.
 * Note: the tree does not have to be a binary tree.
 * 
 * 
 * Two ways are considered to be different if there is at least one node that
 * has different parents in both ways.
 * 
 * Return:
 * 
 * 
 * 0 if ways == 0
 * 1 if ways == 1
 * 2 if ways > 1
 * 
 * 
 * A rooted tree is a tree that has a single root node, and all edges are
 * oriented to be outgoing from the root.
 * 
 * An ancestor of a node is any node on the path from the root to that node
 * (excluding the node itself). The root has no ancestors.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: pairs = [[1,2],[2,3]]
 * Output: 1
 * Explanation: There is exactly one valid rooted tree, which is shown in the
 * above figure.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: pairs = [[1,2],[2,3],[1,3]]
 * Output: 2
 * Explanation: There are multiple valid rooted trees. Three of them are shown
 * in the above figures.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: pairs = [[1,2],[2,3],[2,4],[1,5]]
 * Output: 0
 * Explanation: There are no valid rooted trees.
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= pairs.length <= 10^5
 * 1 <= xi < yi <= 500
 * The elements in pairs are unique.
 * 
 * 
 */

// @lc code=start
/**
 * The code was adapted from https://zxi.mytechroad.com/blog/graph/leetcode-1719-number-of-ways-to-reconstruct-a-tree/. 
 */ 
class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        // build the adjacency map
        unordered_map<int, bitset<501>> mp;
        for (vector<int> p : pairs) {
            mp[p[0]][p[0]] = mp[p[1]][p[1]] = mp[p[0]][p[1]] = mp[p[1]][p[0]] = 1;
        }

        // the root node of the tree must connect with all the nodes
        bool hasRoot = false;
        for (auto iter = mp.begin(); iter != mp.end(); iter++) {
            if (iter->second.count() == mp.size()) {
                hasRoot = true;
                break;
            }
        }

        // there is no root node for the tree
        if (!hasRoot) return 0;

        int multiple = 0;
        for (vector<int> p : pairs) {
            // for each pair, check if any one can be the parent of the other 
            // so that it can cover all the children
            const bitset<501> &all = mp[p[0]] | mp[p[1]];
            int r0 = mp[p[0]] == all;
            int r1 = mp[p[1]] == all;
            // no valid node to be the parent 
            if (r0 + r1 == 0) return 0;
            // if both can be the parent node, there can be multiple trees
            multiple |= (r0 * r1);
        }

        return 1 + multiple;
    }
};
// @lc code=end

