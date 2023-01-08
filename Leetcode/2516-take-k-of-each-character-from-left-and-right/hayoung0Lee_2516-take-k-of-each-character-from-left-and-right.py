class Solution:
    def takeCharacters(self, s: str, k: int) -> int: 
        limits = {ch: s.count(ch) - k for ch in 'abc'}
        
        for key, value in limits.items():
            if value < 0:
                return -1
            
        cnts = {ch: 0 for ch in 'abc'}
        ans = l = 0
        
        for r, c in enumerate(s):
            cnts[c] += 1
            while cnts[c] > limits[c]:
                cnts[s[l]] -= 1
                l += 1
            ans = max(ans, r - l + 1)
            
        
        return len(s) - ans
    