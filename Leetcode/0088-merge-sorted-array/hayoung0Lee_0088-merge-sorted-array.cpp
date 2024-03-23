class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0; 
        int j = 0;
        
        if(n == 0){
            return;
        }
        
        while(i < m && j < n){
            if(nums1[i] >= nums2[j]){
                for(int k = m; k > i; k--){
                   nums1[k] = nums1[k-1]; 
                }
                nums1[i] = nums2[j];
                m++;  
                j++;
            }
            i++;
        }
        
//         std::cout << j << ", " << m << std::endl;
        if(j < nums2.size()){
           for(int k = i; k < nums1.size(); k++){
                nums1[k] = nums2[j];
                j++;
            } 
        }
    }
};