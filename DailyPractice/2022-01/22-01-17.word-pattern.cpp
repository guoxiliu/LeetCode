#include "../leetcode.h"

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> p2i;
        unordered_map<string, int> w2i;

        stringstream input(str);
        int i = 0;
        for(string word; input >> word; i++) {
            if(i == pattern.size())
                return false;
            if(p2i[pattern[i]] != w2i[word])
                return false;
            p2i[pattern[i]] = w2i[word] = i+1;
        }
        return i == pattern.size();
    }
};

