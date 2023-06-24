class Solution {
public:
    vector<vector<int>> ans;
    vector<int> perm;
    int arr[21]; 
    // 0: 0 - 10 = -10, 
    // 1: 1 - 10 = -9,
    // 2: 2 - 10 = -8,
    // ...
    // ...
    // 10: 10 - 10 = 0
    // 11: 11 - 10 = 1
    // ...
    // ...
    // 20: 20 - 10 = 10
    // https://www.algotree.org/algorithms/recursive/permutations_recursion/
    void generate(vector<int> elements){
        if(perm.size() == elements.size()){
            ans.push_back(perm);
        }else{
            for(int i = 0; i < elements.size(); i++){
                if(arr[elements[i] + 10]){
                    continue;
                }
                
                arr[elements[i] + 10] = true;
                perm.push_back(elements[i]);
                
                generate(elements);
                
                perm.pop_back();
                arr[elements[i] + 10] = false;
            }
        }     
    }
    
    vector<vector<int>> permute(vector<int>& nums) {  
        generate(nums);
        return ans;
    }
};