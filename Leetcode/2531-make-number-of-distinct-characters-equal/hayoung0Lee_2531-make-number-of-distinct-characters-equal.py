class Solution:
    def isItPossible(self, word1: str, word2: str) -> bool:
        all_letters = set(word1 + word2)
        m1 = {k: word1.count(k) for k in all_letters}
        m2 = {k: word2.count(k) for k in all_letters}
        
        for w1 in all_letters:
            for w2 in all_letters: 
                if m1[w1] > 0 and m2[w2] > 0:
                    m1[w1] -= 1
                    m1[w2] += 1
                    
                    m2[w2] -= 1
                    m2[w1] += 1
                    
                    m1_filtered = {k: v for k, v in m1.items() if v > 0}
                    m2_filtered = {k: v for k, v in m2.items() if v > 0}
                    
                    if len(m1_filtered) == len(m2_filtered):
                        return True
                    
                    # reset
                    m1[w1] += 1
                    m1[w2] -= 1
                    
                    m2[w2] += 1
                    m2[w1] -= 1
                    
          
        
                        
        return False
                    
                