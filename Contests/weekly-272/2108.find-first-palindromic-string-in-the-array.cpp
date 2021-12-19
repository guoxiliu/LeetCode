class Solution {
public:
    // Check if a string is palindrome
    bool isPalindrome(string &str) {
        int len = str.length();
        for (int i = 0, j = len - 1; i <= j; i++, j--) {
            if (str[i] != str[j]) return false;
        }
        return true;
    }

    string firstPalindrome(vector<string> &words) {
        string ans = "";
        for(string &w : words) {
            // find the first palindromic string and break
            if (isPalindrome(w)) {
                ans = w;
                break;
            }
        }

        return ans;
    }
};
