class Solution:

    def median(self,nums):
        length = len(nums)
        print(length)
        if length%2==0:
            median = nums[length//2-1] + nums[length//2]
            median /= 2
        else:
            median = nums[length//2]

        return median
        
    def concat(self,nums1,nums2):
        idx1,idx2=0,0
        len1,len2=len(nums1),len(nums2)
        print(len1,len2)
        nums = []
        for _ in range(len1+len2):
            if not idx1 >= len1: n1 = nums1[idx1]
            if not idx2 >= len2: n2 = nums2[idx2]

            if idx1 >= len1 :
                nums.append(n2)
                idx2 += 1
                
            elif n1 >= n2:
                nums.append(n2)
                idx2 += 1

            elif idx2 >= len2:
                nums.append(n1)
                idx1 += 1

            elif n1 < n2:
                nums.append(n1)
                idx1 += 1
            


        return nums

    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        
        nums = self.concat(nums1,nums2)
        return self.median(nums)
        