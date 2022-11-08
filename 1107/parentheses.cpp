#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    void generate(int n, int l, int r, string prnt, vector<string>& prnts){
        if (l==n && r == n) prnts.push_back(prnt);
        else{
            if (l < n) generate(n,l+1,r,prnt + '(',prnts);
            if (r < l) generate(n,l,r+1,prnt + ')',prnts);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> prnts = {};
        string prnt;
        generate(n,0,0,prnt,prnts);
        return prnts;
    }
};