/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/
 *
 * algorithms
 * Easy (60.10%)
 * Likes:    276
 * Dislikes: 32
 * Total Accepted:    38.7K
 * Total Submissions: 64.4K
 * Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given an n-ary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * For example, given a 3-ary tree:
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * We should return its level order traversal:
 * 
 * 
 * [
 * ⁠    [1],
 * ⁠    [3,2,4],
 * ⁠    [5,6]
 * ]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The depth of the tree is at most 1000.
 * The total number of nodes is at most 5000.
 * 
 * 
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return {};

        // use BFS traversal and NULL serves as a separator
        queue<Node*> nodeQ;
        nodeQ.push(root);
        nodeQ.push(NULL);

        vector<vector<int>> res;
        vector<int> values;

        while(!nodeQ.empty()) {
            Node* front = nodeQ.front();
            nodeQ.pop();

            if(front == NULL) {
                res.push_back(values);
                values.clear();

                if(nodeQ.empty()) break;
                else nodeQ.push(NULL);
            } else {
                values.push_back(front->val);
                for(Node* child : front->children) {
                    nodeQ.push(child);
                }
            }
        }

        return res;
    }
};

