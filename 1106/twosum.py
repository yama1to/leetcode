class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        length = len(nums)
        for i in range(length-1):
            for j in range(i+1,length):
                if target == (nums[i]+nums[j]):
                    return [i,j]

                    
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        length = len(nums)
        for i in range(length-1):
            for j in range(i+1,length):
                if target == (nums[i]+nums[j]):
                    return [i,j]
    
