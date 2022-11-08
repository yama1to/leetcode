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
    int search(vector<int>& nums, int target) {

        //小さいならば、逆方向から
        if (nums[0] > target){
            for (int i=nums.size() - 1 ; i>0;i--){
                
                if (nums[i] < target)
                    return -1 ;
                else if (nums[i] == target)
                    return nums[target];
                
                if (nums[i] < nums[i-1]) break;
                
            }
        //大きいならば、順方向に
        }else{
            for (int i=0; i<nums.size();i++){
                
                if (nums[i] > target)
                    return -1 ;
                else if (nums[i] == target)
                    return nums[target];
                    
                if (nums[i] > nums[i+1]) break;
            }
        }
    return -1;
    }
};