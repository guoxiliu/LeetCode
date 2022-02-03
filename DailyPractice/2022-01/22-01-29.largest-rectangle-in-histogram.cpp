#include "../leetcode.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> x_stack;
        stack<int> h_stack;

        int sz = heights.size();
        int ans = 0;
        int a, x, h, i;

        for (i = 0; i < sz; i++) {
            x = i;
            h = heights[i];

            while (!h_stack.empty() && h <= h_stack.top()) {
                x = x_stack.top();
                a = h_stack.top() * (i - x);
                ans = max(ans, a);
                x_stack.pop();
                h_stack.pop();
            }

            x_stack.push(x);
            h_stack.push(h);
        }

        while (!h_stack.empty()) {
            a = h_stack.top() * (i - x_stack.top());
            ans = max(ans, a);
            x_stack.pop();
            h_stack.pop();
        }

        return ans;
    }
};
