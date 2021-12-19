class Solution {
public: 
    string addSpaces(string s, vector<int> &spaces) {
        string ans = "";
        int i = 0, j = 0, len = s.length(), sz = spaces.size();
        while (i < len) {
            // check if we need to put a space at the current index
            if (j < sz && i == spaces[j]]) {
                ans.push_back(' ');
                j++; 
                continue;
            }
            ans.push_back(s[i]);
            i++;
        }
        return ans;
    }
};
