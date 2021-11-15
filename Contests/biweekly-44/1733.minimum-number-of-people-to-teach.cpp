/*
 * @lc app=leetcode id=1733 lang=cpp
 *
 * [1733] Minimum Number of People to Teach
 *
 * https://leetcode.com/problems/minimum-number-of-people-to-teach/description/
 *
 * algorithms
 * Medium (39.77%)
 * Likes:    115
 * Dislikes: 276
 * Total Accepted:    5.3K
 * Total Submissions: 13.5K
 * Testcase Example:  '2\n[[1],[2],[1,2]]\n[[1,2],[1,3],[2,3]]'
 *
 * On a social network consisting of m users and some friendships between
 * users, two users can communicate with each other if they know a common
 * language.
 * 
 * You are given an integer n, an array languages, and an array friendships
 * where:
 * 
 * 
 * There are n languages numbered 1 through n,
 * languages[i] is the set of languages the i^​​​​​​th​​​​ user knows, and
 * friendships[i] = [u​​​​​​i​​​, v​​​​​​i] denotes a friendship between the
 * users u^​​​​​​​​​​​i​​​​​ and vi.
 * 
 * 
 * You can choose one language and teach it to some users so that all friends
 * can communicate with each other. Return the minimum number of users you need
 * to teach.
 * Note that friendships are not transitive, meaning if x is a friend of y and
 * y is a friend of z, this doesn't guarantee that x is a friend of z.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
 * Output: 1
 * Explanation: You can either teach user 1 the second language or user 2 the
 * first language.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 3, languages = [[2],[1,3],[1,2],[3]], friendships =
 * [[1,4],[1,2],[3,4],[2,3]]
 * Output: 2
 * Explanation: Teach the third language to users 1 and 3, yielding two users
 * to teach.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= n <= 500
 * languages.length == m
 * 1 <= m <= 500
 * 1 <= languages[i].length <= n
 * 1 <= languages[i][j] <= n
 * 1 <= u​​​​​​i < v​​​​​​i <= languages.length
 * 1 <= friendships.length <= 500
 * All tuples (u​​​​​i, v​​​​​​i) are unique
 * languages[i] contains only unique values
 * 
 * 
 */

// @lc code=start
/**
 * From the description we are supposed to teach only one language, so we can
 * try each language.
 * 
 */
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& L, vector<vector<int>>& F) {
        int userNum = L.size(), friendNum = F.size();
        
        // sort the language list of each user
        for (int i = 0; i < userNum; i++) {
            sort(L[i].begin(), L[i].end());
        }
        
        // check if two users have any common language
        vector<bool> canComm(friendNum, false);
        for (int i = 0; i < friendNum; i++) {
            vector<int> inter;
            int x = F[i][0]-1, y = F[i][1]-1;
            set_intersection(L[x].begin(), 
                L[x].end(), L[y].begin(), 
                L[y].end(), back_inserter(inter));
            if (!inter.empty()) canComm[i] = true;
        }
        
        int ans = INT_MAX;
        // loop each language
        for (int i = 1; i <= n; i++) {
            int cur = 0;
            vector<bool> teach(userNum, false); // avoid duplication
            // loop each friendship
            for (int j = 0; j < friendNum; j++) {
                if (!canComm[j]) {
                    int x = F[j][0]-1, y = F[j][1]-1;
                    if (find(L[x].begin(), L[x].end(), i) == L[x].end()) {
                        if (!teach[x]) {
                            cur++;
                            teach[x] = true;
                        }
                    }
                    if (find(L[y].begin(), L[y].end(), i) == L[y].end()) {
                        if (!teach[y]) {
                            cur++;
                            teach[y] = true;
                        }
                    }
                }
            }
            if (cur < ans) ans = cur;
        }

        return ans;
    }
};
// @lc code=end

