class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        heap = []
        for i in nums: 
            heappush(heap, (-i, i))
            
        answer = 0
        for i in range(k): 
            elem = heappop(heap)[1]
            answer += elem
            new_elem = ceil(elem / 3)
            heappush(heap, (-new_elem, new_elem))
           
        return answer
        