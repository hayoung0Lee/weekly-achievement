class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        m = {}
        ids = []
        
        for id, value in nums1:
            m[id] = value
            ids.append(id)
            
        for id, value in nums2:
            if id in m:
                m[id] += value
            else:
                m[id] = value
            ids.append(id)
            
        unique_id = sorted(set(ids))
        
        ans = []
        for i in unique_id:
            ans.append([i, m[i]])
            
        return ans
                
                
                
                