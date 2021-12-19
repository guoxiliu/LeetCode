class Solution {
public:
    long long subArrayRanges(vector<int> &nums) {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n-1; i++) {
            long long cur_min = nums[i], cur_max = nums[i];
            // use the sliding window to update the minimum and maximum
            for (int j = i+1; j < n; j++) {
                if (nums[j] < cur_min) cur_min = nums[j];
                if (nums[j] > cur_max) cur_max = nums[j];
                ans += (cur_max - cur_min);
            }
        }
        return ans;
    }
};
