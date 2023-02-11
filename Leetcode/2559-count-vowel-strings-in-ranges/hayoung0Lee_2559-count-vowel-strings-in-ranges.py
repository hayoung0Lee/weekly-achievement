class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        arr = [0 for _ in words]
        vowels = "aeiou"
        
        for index, w in enumerate(words):
            if w[0] in vowels and w[-1] in vowels: 
                if index == 0:
                    arr[index] = 1
                else:
                    arr[index] = arr[index-1] + 1
            else:
                if index == 0:
                    arr[index] = 0
                else:
                    arr[index] = arr[index-1]
        
        answer = []
        for q in queries:
            q_start = q[0]
            q_end = q[1]
            
            if q_start == 0:
                answer.append(arr[q_end])
            else:
                answer.append((arr[q_end] - arr[q_start-1]))
        
        return answer
        