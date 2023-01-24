class Solution:
    def alternateDigitSum(self, n: int) -> int:
        str_n = str(n)
        sign = 1
        ans = 0
        for index in range(len(str_n)):
            ans += int(str_n[index]) * sign
            sign *= -1
 
        return ans
        
        