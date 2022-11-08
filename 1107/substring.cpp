#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> seen = {};
        int l = 0;
        int output = 0;

        for(int r=0;r<s.size();r++){
            //未発見なら
            if (!seen.count(s[r])==1){
                output = max(output,r-l+1);
            //発見しているなら
            }else{
                if (seen[s[r]] < l) output = max(output,r-l+1);
                else l = seen[s[r]] + 1;
            }
            seen[s[r]] = r;
        }
        return output;
    }
};
