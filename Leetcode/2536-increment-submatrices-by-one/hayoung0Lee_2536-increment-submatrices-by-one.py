class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        ans = [[0] * (n + 1) for i in range(n + 1)]
    
        for [r1, c1, r2, c2] in queries: 
            for r in range(r1, r2+1):
                ans[r][c1] += 1
                ans[r][c2+1] -= 1
        
        for i in range(n): 
            for j in range(1, n): 
                ans[i][j] += ans[i][j-1]
                  
        return [ans[i][0:n] for i in range(0,n)]