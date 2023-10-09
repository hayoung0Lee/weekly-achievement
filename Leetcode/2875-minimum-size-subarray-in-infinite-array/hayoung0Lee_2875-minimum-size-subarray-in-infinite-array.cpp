class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long int arraySum = 0; 
        
        // arrSum 을 구한다. 
        for(int i = 0; i < nums.size(); i++){
            arraySum += nums[i];
        }
        
        int subArrayLength = 0;
        
        if(target > arraySum){
            subArrayLength = (target / arraySum) * nums.size(); // 연속된 sum의 수
            target = target % arraySum; // 남은 sum
        }
        
        if(target == 0){
            return subArrayLength;
        }
        
        int n = nums.size();
        for(int i = 0; i < n; i++){
            nums.push_back(nums[i]); // 연결해서 붙여서, subArray가 제대로 나오게 한다. 
        }
        
        int mini = INT_MAX;
        unordered_map<int, int> mp;
        long long currentSum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            currentSum += nums[i];
            
            if(target == currentSum) {
                mini = min(mini, i+1);
            }else if(mp.find(currentSum - target) != mp.end()){
                mini = min(mini, i - mp[currentSum - target]);    
            }      
            
            mp[currentSum] = i; 
        }
        
        if(mini == INT_MAX) {
            return -1;
        }
        
        return subArrayLength + mini;
    }
};