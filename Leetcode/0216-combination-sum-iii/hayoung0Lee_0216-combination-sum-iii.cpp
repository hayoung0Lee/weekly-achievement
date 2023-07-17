class Solution {
    int candidate[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int checker[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<vector<int>> answer;
    vector<int> arr;
    int sum = 0;
    int counter = 0;
    
    void recursive(int k, int n, int sum, int index){
        if(counter > k || sum > n){
            return;
        }
        
        if(counter == k){
            if(sum == n) {
                answer.push_back(arr);           
            }
            return;
        }
        
        for(int i = index; i < 9; i++){
            if(checker[i] == 0){
                // 포함 시킬때
                checker[i]++;
                arr.push_back(candidate[i]);
                counter++;
                
                recursive(k, n, sum + candidate[i], i + 1);
                
                checker[i]--;
                arr.pop_back();
                counter--;
            }
             // 포함 안시킬때
             // recursive(k, n, sum, i + 1);
        }
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        recursive(k, n, 0, 0);
        return answer;    
    }
};