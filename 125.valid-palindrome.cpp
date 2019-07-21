/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        std::transform(s.begin(), s.end(), s.begin(), ::toupper);
        int i = 0, j = s.size()-1;
        while (i <= j){
            if(!isalnum(s[i])) {
                i++; continue;
             } 
            if(!isalnum(s[j])) {
                j--; continue;
             }
            if(s[i] != s[j]) {
                return false;
            }
            i++; j--;
        }
        return true;
    }
};

