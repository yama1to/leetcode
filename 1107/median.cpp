#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double median(vector<int>& nums){
        double median;
        int len = nums.size();
        int center = (int)len/2;
        

        if(len%2==0){
            median = nums[center - 1] + nums[center];
            median = median/2.0;
        }else{
            median = nums[center];
        }

        return median;
    }
    vector<int> concat(vector<int>& nums1, vector<int>& nums2){
        vector<int> nums = {};
        int idx1,idx2;
        idx1 = 0;
        idx2 = 0;

        for(int i=0; i<nums1.size()+nums2.size();i++){
            if(idx1 >= nums1.size()){
                nums.insert(nums.end(),nums2[idx2]);
                idx2 += 1;
            }
            else if(idx2 >= nums2.size() || nums1[idx1] < nums2[idx2]){
                nums.insert(nums.end(),nums1[idx1]);
                idx1 += 1;
            }
            else if(nums1[idx1] >= nums2[idx2]){
                nums.insert(nums.end(),nums2[idx2]);
                idx2 += 1;
            }
            else if(nums1[idx1] < nums2[idx2]){
                nums.insert(nums.end(),nums1[idx1]);
                idx1 += 1;
            }
        }

        return nums;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums = concat(nums1,nums2);
        return median(nums);
    }
};



int main (){
    Solution s;
    vector<int> nums1 = {10000};
    vector<int> nums2 = {10001};
    double median = s.findMedianSortedArrays(nums1,nums2);
    cout << median << endl;
    return 0;
}