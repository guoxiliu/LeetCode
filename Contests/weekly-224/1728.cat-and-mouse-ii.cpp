/*
 * @lc app=leetcode id=1728 lang=cpp
 *
 * [1728] Cat and Mouse II
 *
 * https://leetcode.com/problems/cat-and-mouse-ii/description/
 *
 * algorithms
 * Hard (41.43%)
 * Likes:    126
 * Dislikes: 21
 * Total Accepted:    3.8K
 * Total Submissions: 9.2K
 * Testcase Example:  '["####F","#C...","M...."]\n1\n2'
 *
 * A game is played by a cat and a mouse named Cat and Mouse.
 * 
 * The environment is represented by a grid of size rows x cols, where each
 * element is a wall, floor, player (Cat, Mouse), or food.
 * 
 * 
 * Players are represented by the characters 'C'(Cat),'M'(Mouse).
 * Floors are represented by the character '.' and can be walked on.
 * Walls are represented by the character '#' and cannot be walked on.
 * Food is represented by the character 'F' and can be walked on.
 * There is only one of each character 'C', 'M', and 'F' in grid.
 * 
 * 
 * Mouse and Cat play according to the following rules:
 * 
 * 
 * Mouse moves first, then they take turns to move.
 * During each turn, Cat and Mouse can jump in one of the four directions
 * (left, right, up, down). They cannot jump over the wall nor outside of the
 * grid.
 * catJump, mouseJump are the maximum lengths Cat and Mouse can jump at a time,
 * respectively. Cat and Mouse can jump less than the maximum length.
 * Staying in the same position is allowed.
 * Mouse can jump over Cat.
 * 
 * 
 * The game can end in 4 ways:
 * 
 * 
 * If Cat occupies the same position as Mouse, Cat wins.
 * If Cat reaches the food first, Cat wins.
 * If Mouse reaches the food first, Mouse wins.
 * If Mouse cannot get to the food within 1000 turns, Cat wins.
 * 
 * 
 * Given a rows x cols matrix grid and two integers catJump and mouseJump,
 * return true if Mouse can win the game if both Cat and Mouse play optimally,
 * otherwise return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: grid = ["####F","#C...","M...."], catJump = 1, mouseJump = 2
 * Output: true
 * Explanation: Cat cannot catch Mouse on its turn nor can it get the food
 * before Mouse.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: grid = ["M.C...F"], catJump = 1, mouseJump = 4
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = ["M.C...F"], catJump = 1, mouseJump = 3
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: grid = ["C...#","...#F","....#","M...."], catJump = 2, mouseJump = 5
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: grid = [".M...","..#..","#..#.","C#.#.","...#F"], catJump = 3,
 * mouseJump = 1
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * rows == grid.length
 * cols = grid[i].length
 * 1 <= rows, cols <= 8
 * grid[i][j] consist only of characters 'C', 'M', 'F', '.', and '#'.
 * There is only one of each character 'C', 'M', and 'F' in grid.
 * 1 <= catJump, mouseJump <= 8
 * 
 * 
 */

// @lc code=start
/**
 * The maximum size of the grid is 8 * 8 = 64, and after 64 * 2 = 128 turns, 
 * the mouse and cat should be able to go whatever place they want (if we assume 
 * the jump length to be the smallest, i.e., 1).
 * The code was adapted from https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1728-cat-and-mouse-ii/.
 */ 
class Solution {
private: 
    int m, n;  // rows and cols
    int CJ, MJ, limit;  // cat jumps, mouse jump, and grid limit
    vector<vector<vector<int>>> seen;  // array of states
    const vector<pair<int, int>> directions =  // down, up, left, right
        {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    bool dfs(vector<string> &grid, int mouse, int cat, int turn, const int &food) {
        bool isCat = turn & 1;
        if (cat == food || cat == mouse || turn >= limit) return isCat;
        if (mouse == food) return !isCat;
        int &ans = seen[mouse][cat][turn];
        if (ans != -1) return ans;

        const int cur = isCat ? cat : mouse;
        const int jumps = isCat ? CJ : MJ;
        for (pair<int, int> dir : directions) {
            for (int j = 0; j <= jumps; j++) {
                const int x = (cur % n) + dir.first * j;
                const int y = (cur / n) + dir.second * j;
                const int pos = y * n + x;
                if (x < 0 || x >= n || y < 0 || y >= m || grid[y][x] == '#') break;
                // update the position of mouse or cat
                if (isCat) cat = pos; 
                else mouse = pos;
                if (!dfs(grid, mouse, cat, turn+1, food)) return ans = true;
            }
        }
        return ans = false;
    }

public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        CJ = catJump, MJ = mouseJump;
        m = grid.size(), n = grid[0].size();
        // get the positions of mouse, cat, and food
        int mouse, cat, food;
        for (int pos = 0; pos < m * n; pos++) {
            int row = pos / n, col = pos % n;
            if (grid[row][col] == 'M') mouse = pos;
            else if (grid[row][col] == 'C') cat = pos;
            else if (grid[row][col] == 'F') food = pos;
        }

        limit = m * n * 2;
        seen = vector<vector<vector<int>>>(m*n, vector<vector<int>>(m*n, vector<int>(limit+1, -1)));
        return dfs(grid, mouse, cat, 0, food);
    }
};
// @lc code=end

