#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size(),i,l;


        for(i=len-2 ;i>= 0 ; i--){
            if (nums[i] < nums[i+1]) break;
        }
        if (i < 0){
            reverse(nums.begin(),nums.end());
        }else{
            for (l = len - 1; l > i; l--){
                if(nums[l] > nums[i]) break;
            }
            swap(nums[i],nums[l]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};



int main(){
    Solution s ;
    vector<int> vec = {2,3,1};
    s.nextPermutation(vec);
    for(int i : vec){
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}

