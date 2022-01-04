class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n == 1) return vector<int>{0}; 
        vector<int> ans;
        vector<unordered_set<int>> adj(n);
        for (vector<int> &e : edges) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1) {
                q.push(i);
            }
        }

        while (n > 2) {
            int sz = q.size();
            n -= sz;
            for (int i = 0; i < sz; i++) {
                int f = q.front(); q.pop();
                for (const int &a : adj[f]) {
                    adj[a].erase(f);
                    if (adj[a].size() == 1) q.push(a);
                }
            }
        }

        while (!q.empty()) {
            ans.emplace_back(q.front());
            q.pop();
        }

        return ans;
    }
};

