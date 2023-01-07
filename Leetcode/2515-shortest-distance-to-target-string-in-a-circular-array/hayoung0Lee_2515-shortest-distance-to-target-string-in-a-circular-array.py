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
        
        rightArr = words[startIndex:] + words[0:startIndex]
        leftArr = words[startIndex::-1] + words[-1:startIndex:-1]
        
        for i in range(len(rightArr)): 
            if rightArr[i] == target: 
                if answer > i: 
                    answer = i
            
        for i in range(len(leftArr)): 
            if leftArr[i] == target: 
                if answer > i: 
                    answer = i
        
        return answer