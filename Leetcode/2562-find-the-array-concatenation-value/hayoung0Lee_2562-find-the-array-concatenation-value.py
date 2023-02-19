class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        ans = 0
        while nums:
            first = nums[0]
            second = nums[-1]
        
            if len(nums) == 1:
                ans += first
                nums.pop(0)
            else:
                ans += int(str(first) + str(second))
                nums.pop(0)
                nums.pop()
                
        return ans