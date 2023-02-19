class Solution:
    def smaller(self, nums, target):
        """
            Get paris of nums smaller or equal to target value
        """
        left = 0
        right = len(nums) - 1
        ans = 0
        
        while left < right:
            s = nums[left] + nums[right]
            
            if s <= target:
                ans += (right - left)
                left += 1
            else:
                right -= 1
                
        return ans
        
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        return self.smaller(nums, upper) - self.smaller(nums, lower - 1)        