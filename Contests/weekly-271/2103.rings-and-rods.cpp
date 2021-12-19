class Solution {
public: 
    int countPoints(string rings) {
        vector<vector<bool>> rods(10, vector<bool>(3, false));
        int n = rings.size();
        for (int i = 0; i < n-1; i+=2) {
            int idx = rings[i+1] - '0';
            if (rings[i] == 'R') {
                rods[idx][0] = true;
            }
            else if (rings[i] == 'G') {
                rods[idx][1] = true;
            }
            else {
                rods[idx][2] = true;
            }
        }

        int ans = 0;
        // check if the rod has all three colors
        for (int i = 0; i < 10; i++) {
            if (rods[i][0] && rods[i][1] && rods[i][2])
                ans++;
        }

        return ans;
    }
};
