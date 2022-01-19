#include "../leetcode.h"

class Solution {
public:
  int myAtoi(string s) {
    int i = 0, len = s.size();
    while(i < len && s[i] == ' '){
      i++;
    }
    int sign = 0, res = 0;
    if(i < len){
      if(s[i] == '+'){
        sign = 1;
        i++;
      }
      else if(s[i] == '-'){
        sign = -1;
        i++;
      }
      else if(s[i] >= '0' && s[i] <= '9'){
        sign = 1;
      }
      else{
        return 0;
      }
    }

    while(i < len && isdigit(s[i])){
      int digit = s[i] - '0';
      if(res <= INT_MAX/10){
        res *= 10;
      }
      else{
        return sign==1? INT_MAX:INT_MIN;
      }
      if(INT_MAX-digit >= res){
        res += digit;
      }
      else{
        return sign==1? INT_MAX:INT_MIN;
      }
      i++;
    }
    return sign*res;
  }
};

