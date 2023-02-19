class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        ans = 0
        left = 0
        right = len(nums) - 1
        while left <= right:
            first = nums[left]
            second = nums[right]
        
            if left == right:
                ans += first
            else:
                ans += int(str(first) + str(second))
            left += 1
            right -= 1
        return ans