class Solution:
    def leftRigthDifference(self, nums: List[int]) -> List[int]:
        leftSum = [0]
        rightSum = [0]
        
        for index, value in enumerate(nums[0: -1]):
            leftSum.append(leftSum[index] + value)
       
        for index, value in enumerate(reversed(nums[1:])):
            rightSum.append(rightSum[index] + value)
        
        rightSum.reverse()
        
        ans = []
        
        for a, b in zip(leftSum, rightSum):
            ans.append(abs(a - b))
        
        return ans