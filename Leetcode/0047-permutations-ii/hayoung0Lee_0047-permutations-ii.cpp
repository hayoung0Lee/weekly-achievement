class Solution {
public:
    set<vector<int>> ans;
    int arr[21];
    vector<int> perm;
    
    void generate(vector<int>& nums){
        if(perm.size() == nums.size()){
            ans.insert(perm);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(arr[nums[i] + 10] == 0) {
                continue;
            }
            
            perm.push_back(nums[i]);
            arr[nums[i] + 10]--;
            
            generate(nums);
            
            arr[nums[i] + 10]++;
            perm.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            arr[nums[i] + 10]++;
        }
        
        generate(nums);
        
        vector<vector<int>> v(ans.begin(), ans.end());
        return v;
    }
};