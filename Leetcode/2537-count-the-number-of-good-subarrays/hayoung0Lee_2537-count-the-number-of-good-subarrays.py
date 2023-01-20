class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        N = len(nums)
        
        ans = 0
        left = 0
        counts = Counter()
        pairs = 0
        
        for right in range(N):
            pairs += counts[nums[right]] # if it is 2, get two
            counts[nums[right]] += 1 # add two
            
            while pairs >= k:
                # increase left
                counts[nums[left]] -= 1
                pairs -= counts[nums[left]]
                left += 1
            
            ans += left # this is number of good sub arrays
        
        
        return ans