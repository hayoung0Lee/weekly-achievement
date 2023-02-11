class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        for t in range(k):
            max_index = 0
            max_value = gifts[max_index]
            
            for index, g in enumerate(gifts):
                if g > max_value:
                    max_index = index
                    max_value = g
            
            gifts[max_index] = math.floor(math.sqrt(max_value))
            
        return sum(gifts)    
                