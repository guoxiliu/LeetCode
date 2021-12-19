class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int rBoundary = max(startPos, fruits[n-1][0]);
        vector<int> amount(rBoundary+2, 0);
        for(vector<int> &f : fruits) {
            amount[f[0]+1] = f[1];
        }
        
        // get the prefix sum 
        for (int i = 1; i <= rBoundary+1; i++) {
            amount[i] += amount[i-1];
        }
        
        int ans = 0;
        // the right distance from the start position
        for (int rdist = 0; rdist <= min(k, rBoundary-startPos); rdist++) {
            // if we turn around, how far is the left distance from the start position
            int ldist = max(0, k - 2 * rdist);
            // then we can get the leftmost and rightmost position 
            int leftmost = max(0, startPos - ldist), rightmost = startPos + rdist;
            // use the prefix sum to get the fruit number 
            ans = max(ans, amount[rightmost+1] - amount[leftmost]);
        }
        
        for (int ldist = 0; ldist <= min(k, startPos); ldist++) {
            int rdist = max(0, k - 2 * ldist);
            int leftmost = startPos - ldist, rightmost = min(rBoundary, startPos + rdist);
            ans = max(ans, amount[rightmost+1] - amount[leftmost]);
        }
        
        
        return ans;
    }
};
