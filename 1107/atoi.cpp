#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;


class Solution {
public:
    int myAtoi(string s) {
        int idx = 0;
        signed int integer;
        int len = s.size();
        if (len==0) return 0;

        while (idx < len && s[idx] == ' ') ++idx;

        bool isNegative = false;
        if (idx < len){
            if (s[0]=='-') isNegative = true;

            if (s[idx] == '-'){
                isNegative = true;
                ++idx;
            }else if (s[idx] == '+'){
                ++idx;
            }
        }

        int result = 0;
        while (idx < len && isDigit(s[idx])){
            int digit = s[idx] - '0';
            if (result > (INT32_MAX/10) || (result == (INT32_MAX/10) && digit > 7)){
                return isNegative ? INT32_MIN : INT32_MAX;
            }
            result = (result * 10) + digit;
            ++idx;
        }
        return isNegative ? -result : result;
    }
private:
  bool isDigit(char ch){
    return ch >= '0' && ch <= '9';
  }
};