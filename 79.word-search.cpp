/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (30.68%)
 * Total Accepted:    265.3K
 * Total Submissions: 862.2K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // DFS 
    bool check (vector<vector<char>>& board, string word, int row, int col) {
        if (word.size() == 0)
            return true;

        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[0]) 
            return false;

        char c = board[row][col];
        // change original character
        board[row][col] = '\0';
        string new_word = word.substr(1);

        bool ret = (check(board, new_word, row+1, col) ||
            check(board, new_word, row-1, col) ||
            check(board, new_word, row, col+1) ||
            check(board, new_word, row, col-1));

        board[row][col] = c;
        
        return ret;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0)
            return false;
        
        int m = board.size(), n = board[0].size();
        // Start from the first character
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (check(board, word, i, j))
                        return true;
                }
            }
        }

        return false;
    }
};

