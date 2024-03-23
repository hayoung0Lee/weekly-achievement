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
                   nums1[k] = nums1[k-1];  // 새로운 원소가 추가되면 뒤로 민다
                }
                nums1[i] = nums2[j];
                s++;  // 그리고 빈자리를 하나 줄인다, 한개가 추가되었으니 1을 증가시킴
                j++; // 그리고 그다음 원소 체크를 위해 1을 증가시킴
            }
            i++; // 더 크던, 작던 같던 nums1[i]는 검사를 마쳤으므로 증가시킨다. 
        }
        
        if(j < n){
           for(int k = i; k < nums1.size(); k++){
                nums1[k] = nums2[j]; // 나머지 원소를 옮겨준다
                j++;
            } 
        }
    }
};