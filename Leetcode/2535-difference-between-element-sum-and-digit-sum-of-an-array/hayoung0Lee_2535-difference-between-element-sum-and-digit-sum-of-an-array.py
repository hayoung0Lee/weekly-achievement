class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        elem_sum = 0
        digit_sum = 0
        for i in nums: 
            elem_sum += i
            
            while i:
                digit_sum += i % 10
                i //= 10    
        
        return abs(elem_sum - digit_sum)