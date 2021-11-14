/*
 * @lc app=leetcode id=2076 lang=cpp
 *
 * [2076] Process Restricted Friend Requests
 *
 * https://leetcode.com/problems/process-restricted-friend-requests/description/
 *
 * algorithms
 * Hard (44.53%)
 * Likes:    73
 * Dislikes: 1
 * Total Accepted:    1.8K
 * Total Submissions: 4.1K
 * Testcase Example:  '3\n[[0,1]]\n[[0,2],[2,1]]'
 *
 * You are given an integer n indicating the number of people in a network.
 * Each person is labeled from 0 to n - 1.
 * 
 * You are also given a 0-indexed 2D integer array restrictions, where
 * restrictions[i] = [xi, yi] means that person xi and person yi cannot become
 * friends, either directly or indirectly through other people.
 * 
 * Initially, no one is friends with each other. You are given a list of friend
 * requests as a 0-indexed 2D integer array requests, where requests[j] = [uj,
 * vj] is a friend request between person uj and person vj.
 * 
 * A friend request is successful if uj and vj can be friends. Each friend
 * request is processed in the given order (i.e., requests[j] occurs before
 * requests[j + 1]), and upon a successful request, uj and vj become direct
 * friends for all future friend requests.
 * 
 * Return a boolean array result, where each result[j] is true if the j^th
 * friend request is successful or false if it is not.
 * 
 * Note: If uj and vj are already direct friends, the request is still
 * successful.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, restrictions = [[0,1]], requests = [[0,2],[2,1]]
 * Output: [true,false]
 * Explanation:
 * Request 0: Person 0 and person 2 can be friends, so they become direct
 * friends. 
 * Request 1: Person 2 and person 1 cannot be friends since person 0 and person
 * 1 would be indirect friends (1--2--0).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 3, restrictions = [[0,1]], requests = [[1,2],[0,2]]
 * Output: [true,false]
 * Explanation:
 * Request 0: Person 1 and person 2 can be friends, so they become direct
 * friends.
 * Request 1: Person 0 and person 2 cannot be friends since person 0 and person
 * 1 would be indirect friends (0--2--1).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 5, restrictions = [[0,1],[1,2],[2,3]], requests =
 * [[0,4],[1,2],[3,1],[3,4]]
 * Output: [true,false,true,false]
 * Explanation:
 * Request 0: Person 0 and person 4 can be friends, so they become direct
 * friends.
 * Request 1: Person 1 and person 2 cannot be friends since they are directly
 * restricted.
 * Request 2: Person 3 and person 1 can be friends, so they become direct
 * friends.
 * Request 3: Person 3 and person 4 cannot be friends since person 0 and person
 * 1 would be indirect friends (0--4--3--1).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= n <= 1000
 * 0 <= restrictions.length <= 1000
 * restrictions[i].length == 2
 * 0 <= xi, yi <= n - 1
 * xi != yi
 * 1 <= requests.length <= 1000
 * requests[j].length == 2
 * 0 <= uj, vj <= n - 1
 * uj != vj
 * 
 * 
 */

// @lc code=start
/**
 * The solution is to use the union find (or disjoint set) to check if two groups of 
 * two people are in the restriction list. 
 */ 
class Solution {
    int group[1005];
public:
    // Find the group of a given person.
    int search(int i) {
        int g = group[i];
        while (group[g] != g) {
            g = group[g];
        }
        group[i] = g;
        return g;
    }
    
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        // initialize the group, each person is an individual group
        for (int i = 0; i < n; i++) {
            group[i] = i;
        }
        
        vector<bool> ans;
        for (vector<int> req : requests) {
            int x = search(req[0]), y = search(req[1]);
            // check if they are already friends
            if (x == y) {
                ans.push_back(true);
                continue;
            }
            
            bool res = true;
            // check if the friend request violates any restrictions
            for (vector<int> r : restrictions) {
                if ((search(r[0]) == x && search(r[1]) == y) || (search(r[0]) == y && search(r[1]) == x)) {
                    res = false;
                    break;
                }
            }
            ans.push_back(res);
            // if not, connect two people
            if (res) group[x] = y;
        }
        
        return ans;
    }
};
// @lc code=end

