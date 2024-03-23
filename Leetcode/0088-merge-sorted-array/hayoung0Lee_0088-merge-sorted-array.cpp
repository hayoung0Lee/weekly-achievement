class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0; 
        int j = 0;
        
        // 만약에 n이 0이면 그냥 return하면 된다
        if(n == 0){
            return;
        }
        
        int s = m; // 빈자리를 뺀 길이를 체크한다, 1 1 1 0 0 0이면 1 1 1인 3을 체크해둠
        
        while(i < s && j < n){ //  
            if(nums1[i] >= nums2[j]){
                for(int k = s; k > i; k--){
                   nums1[k] = nums1[k-1]; 
                }
                nums1[i] = nums2[j];
                s++;  
                j++;
            }
            i++;
        }
        
        if(j < n){
           for(int k = i; k < nums1.size(); k++){
                nums1[k] = nums2[j];
                j++;
            } 
        }
    }
};