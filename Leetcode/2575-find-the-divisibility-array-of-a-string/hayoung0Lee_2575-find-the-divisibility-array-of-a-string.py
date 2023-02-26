class Solution:
    def divisibilityArray(self, word: str, m: int) -> List[int]:
        rem = 0
        ans = []
        
        for i in word:
            rem = (rem * 10 + int(i)) % m
            
            if rem == 0:
                ans.append(1)
            else:
                ans.append(0)
        
        return ans