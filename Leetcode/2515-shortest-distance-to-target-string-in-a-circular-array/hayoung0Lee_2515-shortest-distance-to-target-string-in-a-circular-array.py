class Solution:
    def closetTarget(self, words: List[str], target: str, startIndex: int) -> int:
        # I am leetcode hello hello
        # i hello hello leetcode am
        
        # a b leetcode
        # a leetcode b
        
        # i eat leetcode
        # i leetcode eat
        n = len(words)
        
        if target not in words:
            return -1

        answer = float('inf')
        
        targets = [i for i in range(n) if words[i] == target]
        
        for index in targets: 
            forward = 0
            if startIndex <= index: 
                forward = index - startIndex
            else: 
                forward = (n + index) - startIndex
                
            backward = 0
            if startIndex >= index:
                backward = startIndex - index
            else: 
                backward = startIndex - (index - n)
            
            answer = min(answer, forward, backward)
        
        
        return answer