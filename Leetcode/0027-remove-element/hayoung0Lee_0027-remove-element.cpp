class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
    
        while(i < n){
            // 같으면 위치를 다 옮겨준다, 그리고 길이를 1만큼 줄여서 길이를 줄인다
            if(nums[i] == val){
                for(int j = i; j < nums.size() - 1; j++){
                    nums[j] = nums[j + 1];
                }
                // 이때는 i값을 올리지 않는다, 왜냐하면 중복된 값이 있을수도 있기 때문에
                n--;
            } else {
                // 값이다르면 그냥 다음값체크하러간다
                i++;
            }
        }
        
        return n;
    }
};