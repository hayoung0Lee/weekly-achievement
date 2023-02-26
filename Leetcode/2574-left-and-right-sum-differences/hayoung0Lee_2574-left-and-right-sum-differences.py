class Solution:
    def leftRigthDifference(self, nums: List[int]) -> List[int]:
        total = sum(nums)
        leftSum = 0
        
        ans = []
        for i in nums: 
            # sum([10, 4, 8, 3]) - 0 = Sum of [10, 4, 8, 3]
            # to get right sum, subtract current value 
            
            # sum([10, 4, 8, 3]) - 10 = Sum of [4, 8, 3]
            # to get right sum, subtract current value
            
            # sum([10, 4, 8, 3]) - 14 = Sum of [8, 3]
            # to get right sum, subtract current value
            
            # sum([10, 4, 8, 3]) - 22 = Sum of [3]
            # to get right sum, subtract current value
            rightSum = (total - leftSum) - i 
            ans.append(abs(rightSum - leftSum))
            leftSum += i 
        
        return ans
        