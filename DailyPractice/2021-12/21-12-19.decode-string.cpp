#include "../leetcode.h"

class Solution {
public: 
    string decodeString(string s) {
        stack<string> st;
        stack<int> numbers;
        string ans = "";
        int num = 0;
        for (char &c : s) {
            if (isdigit(c)) 
                num = num * 10 + (c - '0');
            else if (c == '[') {
                // save the previous string to the stack
                st.push(ans);
                // get the number before '['
                numbers.push(num);
                // reset the variables
                ans = ""; num = 0;
            }
            else if (c == ']') {
                string cur = ans; 
                // get the repeating times from the stack 
                // and repeat the current string 
                int times = numbers.top()-1; numbers.pop();
                while (times--) ans.append(cur);
                string top = st.top(); st.pop();
                // append the string to the previous one from stack
                ans = top + ans;
            }
            else ans.push_back(c);
        }

        return ans;
    }

};
