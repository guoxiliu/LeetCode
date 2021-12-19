class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                dp[i&1][j] = (matrix[i][j] == '1' ? 1 + min({dp[(i+1)&1][j], dp[i&1][j+1], dp[(i+1)&1][j+1]}) : 0);
                ans = max(ans, dp[i&1][j]);
            }
        }
        return ans * ans;
    }
};
