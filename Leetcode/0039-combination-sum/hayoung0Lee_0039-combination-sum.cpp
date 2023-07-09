class Solution {
    vector<vector<int>> answer;
    
    void recursive(vector<int>& candidates, vector<int> arr, int currentIndex, int currentSum, int target){
        if(currentSum > target){
            return;
        }
        
        if(currentSum == target){
            answer.push_back(arr);
        }
        
        for(int i = currentIndex; i < candidates.size(); i++){
            arr.push_back(candidates[i]);
            recursive(candidates, arr, i, currentSum + candidates[i], target);
            arr.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        recursive(candidates, vector<int>(), 0, 0, target);
        
        return answer;
    }
};