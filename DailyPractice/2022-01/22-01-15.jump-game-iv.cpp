#include "../leetcode.h"

class Solution {
public: 
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n < 1) return 0;
        
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; i++) {
            graph[arr[i]].push_back(i);
        }
        
        vector<int> cur{0};
        unordered_set<int> visited;
        int step = 0;
        
        while (!cur.empty()) {
            vector<int> nexts;
            for (int &node : cur) {
                if (node == n-1) return step;
                for (int &child : graph[arr[node]]) {
                    if (!visited.count(child)) {
                        visited.insert(child);
                        nexts.push_back(child);
                    }
                }
                graph[arr[node]].clear();
                
                if (node + 1 < n && !visited.count(node + 1)) {
                    visited.insert(node + 1);
                    nexts.push_back(node + 1);
                }
                if (node - 1 >= 0 && !visited.count(node - 1)) {
                    visited.insert(node - 1);
                    nexts.push_back(node - 1);
                }
            }
            cur = nexts;
            step++;
        }
        
        return -1;
    }
};
