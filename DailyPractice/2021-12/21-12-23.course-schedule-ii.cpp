#include "../leetcode.h"

class Solution {
    vector<bool> perm, temp;
    vector<vector<int>> adj;
public:
    int visit(int node, vector<int> &ans) {
        if (perm[node]) return 0;
        if (temp[node]) return -1;

        temp[node] = true;
        for (int &m : adj[node]) {
            if(visit(m, ans)) return -1;
        }

        temp[node] = false;
        perm[node] = true;
        ans.push_back(node);
        return 0;
    }

    vector<int> findOrder(int N, vector<vector<int>> &P) {
        // build the adjacency list
        adj = vector<vector<int>>(N);
        for (vector<int> &p : P) {
            adj[p[1]].emplace_back(p[0]);
        }
        perm = vector<bool>(N, false);
        temp = vector<bool>(N, false);

        vector<int> ans;
        for (int i = 0; i < N; i++) {
            if(visit(i, ans)) return vector<int>{};
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
