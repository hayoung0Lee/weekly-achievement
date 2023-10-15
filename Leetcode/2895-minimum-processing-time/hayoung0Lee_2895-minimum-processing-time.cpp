class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        // 1. sort tasks
        std::sort(tasks.begin(), tasks.end(), greater<int>()); // descending
        std::sort(processorTime.begin(), processorTime.end()); // ascending
        
        // 2. processorTime 작은 애부터 네개씩 가져가면서 max를 체크한다. 
        // 이 max중에 max가 답
        int max_max = 0;
        int task_index = 0;
        
        for(int i = 0; i < processorTime.size(); i++){
            int temp_max = processorTime[i] + tasks[task_index];
            
            if(temp_max > max_max){
                max_max = temp_max;
            }
            
            task_index += 4;
        }
             
        return max_max;
    }
};