class Solution {
public: 
    // Find the length of the longest non-decreasing subsequence.
    int lengthOfNDIS(vector<int> &nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            // use upper_bound here instead of lower_bound
            auto it = std::upper_bound(res.begin(), res.end(), nums[i]);
            if (it == res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }

        return res.size();
    }

    int kIncreasing(vector<int> &arr, int k) {
        int n = arr.size(), ans = 0;
        for (int t = 0; t < k; t++) {
            vector<int> tmp;
            // get the subarray with the k interval 
            for (int i = t; i < n; i+=k) {
                tmp.emplace_back(arr[i]);
            }
            int longest = lengthOfLIS(tmp);
            // the minimum operations would be the length of the subarray
            // minus the length of the longest non-decreasing subsequence
            ans += (tmp.size() - longest);
        }
        return ans;
    }
};
