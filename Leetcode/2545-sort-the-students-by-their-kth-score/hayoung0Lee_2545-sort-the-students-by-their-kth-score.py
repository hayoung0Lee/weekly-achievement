class Solution:
    def swap(self, start: int, score: List[List[int]], k: int):
        max_index = start
        max_value = score[start][k]
        
        for i in range(start, len(score)):
            if max_value < score[i][k]:
                max_value = score[i][k]
                max_index = i
    
        for i in range(len(score[start])):
            temp = score[start][i]
            score[start][i] = score[max_index][i]
            score[max_index][i] = temp
            
    def sortTheStudents(self, score: List[List[int]], k: int) -> List[List[int]]:
        for i in range(len(score)):
            self.swap(i, score, k)
        
        return score