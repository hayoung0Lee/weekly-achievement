class Solution {
    int counter[51]; // 1이 몇개, 2가 몇개
    vector<int> unique;
    vector<int> arr;
    vector<vector<int>> answer;
    
    void recursive(int index, int currentSum, int target){
        if(currentSum > target){
            return;
        }
        
        if(currentSum == target){
            answer.push_back(arr); 
            return;
        }
        
        for(int i = index; i < unique.size(); i++){
            int sum = currentSum;
            for(int j = 0; j < counter[unique[i]]; j++){
                sum += unique[i];
                arr.push_back(unique[i]);
                
                recursive(i + 1, sum, target);
            }
            
            for(int j = 0; j < counter[unique[i]]; j++){
                arr.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        for(int i = 0; i < candidates.size(); i++){
            counter[candidates[i]]++; 
            if(counter[candidates[i]] == 1){
                unique.push_back(candidates[i]);
            }
        }
        
        recursive(0, 0, target);
    
        return answer;
    }
};