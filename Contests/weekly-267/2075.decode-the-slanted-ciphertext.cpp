/*
 * @lc app=leetcode id=2075 lang=cpp
 *
 * [2075] Decode the Slanted Ciphertext
 *
 * https://leetcode.com/problems/decode-the-slanted-ciphertext/description/
 *
 * algorithms
 * Medium (49.37%)
 * Likes:    45
 * Dislikes: 9
 * Total Accepted:    3.2K
 * Total Submissions: 6.6K
 * Testcase Example:  '"ch   ie   pr"\n3'
 *
 * A string originalText is encoded using a slanted transposition cipher to a
 * string encodedText with the help of a matrix having a fixed number of rows
 * rows.
 * 
 * originalText is placed first in a top-left to bottom-right manner.
 * 
 * The blue cells are filled first, followed by the red cells, then the yellow
 * cells, and so on, until we reach the end of originalText. The arrow
 * indicates the order in which the cells are filled. All empty cells are
 * filled with ' '. The number of columns is chosen such that the rightmost
 * column will not be empty after filling in originalText.
 * 
 * encodedText is then formed by appending all characters of the matrix in a
 * row-wise fashion.
 * 
 * The characters in the blue cells are appended first to encodedText, then the
 * red cells, and so on, and finally the yellow cells. The arrow indicates the
 * order in which the cells are accessed.
 * 
 * For example, if originalText = "cipher" and rows = 3, then we encode it in
 * the following manner:
 * 
 * The blue arrows depict how originalText is placed in the matrix, and the red
 * arrows denote the order in which encodedText is formed. In the above
 * example, encodedText = "ch ie pr".
 * 
 * Given the encoded string encodedText and number of rows rows, return the
 * original string originalText.
 * 
 * Note: originalText does not have any trailing spaces ' '. The test cases are
 * generated such that there is only one possible originalText.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: encodedText = "ch   ie   pr", rows = 3
 * Output: "cipher"
 * Explanation: This is the same example described in the problem
 * description.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: encodedText = "iveo    eed   l te   olc", rows = 4
 * Output: "i love leetcode"
 * Explanation: The figure above denotes the matrix that was used to encode
 * originalText. 
 * The blue arrows show how we can find originalText from encodedText.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: encodedText = "coding", rows = 1
 * Output: "coding"
 * Explanation: Since there is only 1 row, both originalText and encodedText
 * are the same.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: encodedText = " b  ac", rows = 2
 * Output: " abc"
 * Explanation: originalText cannot have trailing spaces, but it may be
 * preceded by one or more spaces.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= encodedText.length <= 10^6
 * encodedText consists of lowercase English letters and ' ' only.
 * encodedText is a valid encoding of some originalText that does not have
 * trailing spaces.
 * 1 <= rows <= 1000
 * The testcases are generated such that there is only one possible
 * originalText.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    /**
     * The solution is to add the characters from each group in the encoded text 
     * and then remove the trailing spaces.
     */ 
    string decodeCiphertext(string encodedText, int rows) {
        int len = encodedText.length();
        if (len == 0) return "";
        int cols = len / rows;

        string ans = "";
        for (int c = 0; c < cols; c++) {
            for (int r = 0; r < rows; r++) {
                if (c + r >= cols) break;
                else ans += encodedText[r * cols + (c+r)];
            }
        }
        
        size_t end = ans.find_last_not_of(' ');
        return ans.substr(0, end + 1);
    }
};
// @lc code=end

