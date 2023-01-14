class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        neg = 0    
        for i in nums: 
            if i >= 0:
                break
            else:
                neg += 1
        
        pos = 0
        for i in reversed(nums): 
            if i <= 0:
                break
            else:
                pos += 1
        
        return max(neg, pos)