class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++){
            int remaining = target - nums[i];

            if(hash.count(remaining)){
                return {hash[remaining], i};
            }
            hash[nums[i]] = i;
        }
    return {0,0};
    }
};