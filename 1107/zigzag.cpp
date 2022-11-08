#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;


class Solution{
public:
    string convert(string s, int numRows){
        if (numRows == 1) return s;
        vector<string> row_arr;
        for(int i = 0; i<numRows; i++){
            row_arr.insert(row_arr.end(),"");
        }
        int row_idx = 1;
        int goingup = true;
        


        for(int i=0; i<s.size(); i++){
            row_arr[row_idx - 1] += s[i];
            if (row_idx==1) goingup = true;
            else if(row_idx==numRows) goingup = false;

            if (goingup) row_idx += 1;
            else row_idx -= 1;

        }

        // string ans = "";
        // for(int i=0;i<numRows;i++){
        //     ans += row_arr[i];
        // }
        std::ostringstream os;
        std::copy(row_arr.begin(), row_arr.end(), std::ostream_iterator<std::string>(os));
        return os.str();
    }
};