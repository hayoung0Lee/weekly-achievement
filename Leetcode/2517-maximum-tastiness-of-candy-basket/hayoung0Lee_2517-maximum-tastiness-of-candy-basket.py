class Solution:
    def maximumTastiness(self, price: List[int], k: int) -> int:
        n = len(price)
        price.sort()
        
        l = 0
        r = 10 ** 9
        ans = l
        while l <= r:
            mid = (l + r) // 2
            cntOffCancdies = 1 
            last = price[0]
            
            # Counting
            for i in range(n):
                if i == 0: 
                    continue
                if price[i] - last >= mid:
                    cntOffCancdies += 1;
                    last = price[i]
            
            if cntOffCancdies >= k:
                ans = mid
                l = mid + 1
            else:
                r = mid - 1
        return ans