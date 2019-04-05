/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (35.20%)
 * Total Accepted:    323.9K
 * Total Submissions: 920.1K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    // Comparison function for Interval struct.
    static bool comp(const Interval &a, const Interval &b) {
        if (a.start == b.start)
            return a.end < b.end;
        return a.start < b.start;
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        int m = intervals.size();
        if (m == 0 || m == 1) {
            return intervals;
        }

        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), comp);
        res.push_back(intervals[0]);

        for (int i = 1; i < m; i++) {
            if (intervals[i].start <= res.back().end) {
                Interval tmp(res.back().start, max(res.back().end, intervals[i].end));
                res.pop_back();
                res.push_back(tmp);
            } else {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};

