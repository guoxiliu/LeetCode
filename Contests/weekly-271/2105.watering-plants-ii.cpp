class Solution {
public:
    int minimumRefill(vector<int> &plants, int cA, int cB) {
        int sz = plants.size();
        int ans = 0, curA = cA, curB = cB;
        for (int i = 0, j = sz-1; i < sz && j >= 0; i++, j--) {
            // Alice and Bob are watering different plants
            if (i < j) {
                // check Alice's watering can 
                if (curA < plants[i]) {
                    curA = cA;
                    ans++;
                }
                curA -= plants[i];
                // check Bob's watering can
                if (curB < plants[j]) {
                    curB = cB;
                    ans++;
                }
                curB -= plants[j];
            }
            // Alice and Bob are watering the same plant
            else if (i == j) {
                if (curA >= plants[i] || curB >= plants[j]) {
                    break;
                }
                else {
                    ans++;
                    break;
                }
            }
            // finish watering the plants
            else {
                break;
            }
        }
        return ans;
    }
};
